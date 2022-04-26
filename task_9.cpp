#include <iostream>
#include <random>

class LinkedList
{

    struct LLItem
    {
        double value;
        LLItem *next;
    };

private:
    LLItem *root;

public:
    LinkedList()
    {
        root = nullptr;
    }

    void push_back(double value)
    {
        if (root == nullptr)
        {
            root = new LLItem[1];
            root->value = value;
            root->next = nullptr;
        }
        else
        {
            LLItem *curItem = root;
            while (curItem->next != nullptr)
            {
                curItem = curItem->next;
            }
            curItem->next = new LLItem[1];
            curItem = curItem->next;
            curItem->value = value;
            curItem->next = nullptr;
        }
    }

    double get(size_t index){
        using namespace std;
        LLItem *cur = root;
    
        size_t c = 0;

        while (c < index){
            if (cur->next != nullptr){
                cur = cur->next;
            }
            else{
                cerr << "In LinkedList::get(): Wrong index!";
                exit(-1);
            }
            c++;
        }

        return cur->value;

    }

    void pop_back(){
        LLItem *curItem = root;
        if (root == nullptr) return;
        if (root->next == nullptr){
            delete[] root;
            root = nullptr;
            return;
        }



        while (curItem->next->next != nullptr){
            curItem = curItem->next;
        }
        delete[] curItem->next;
        curItem->next = nullptr;

    }

    void remove(size_t index){
        using namespace std;
        LLItem *curItem = root;
        LLItem *prevItem = curItem;
        if (root == nullptr) return;
        size_t cur = 0;

        while (cur < index){
            if (curItem->next != nullptr){
                prevItem = curItem;
                curItem = curItem->next;
            }
            else{
                cerr << "Error in LinkedList::remove(): Wrong index!\n";
                return;
            }
            cur++;
        }

        if (curItem == root){
            LLItem *temp = root->next;
            delete[] root;
            root = temp;
        }
        else{
            prevItem->next = curItem->next;
            delete[] curItem;
        }

    }

    void print()
    {
        using namespace std;
        LLItem *curItem = root;
        if (curItem == nullptr)
            return;
        while (curItem->next != nullptr)
        {
            cout << curItem->value << " ";
            curItem = curItem->next;
        }
        cout << curItem->value << endl;
    }
};

int main()
{
    using namespace std;

    LinkedList ll;

    #define LLSIZE 20

    for (int i = 0; i < LLSIZE; i++){
        ll.push_back(rand() % 200 - 100);
    }

    ll.print();

    //удаляем отрицательные из списка

    size_t deleted_items = 0;

    for (int i = 0; i < (LLSIZE - deleted_items); i++){
        if (ll.get(i) < 0){
            ll.remove(i);
            i--;
            deleted_items++;
        }
    }

    ll.print();

    return 0;
}