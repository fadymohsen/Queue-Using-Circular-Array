#include <iostream>
#include <cassert>
#include <string>
using namespace std;



// START GLOBAL VARIABLES
int max_size;
// END GLOBAL VARIABLES



// START QUEUE IMPLEMENTATION
// --------------------------
template <class t>
class queue{
    int rear;
    int front;
    int length;
    t *arr;

public:
    queue(int size){

        // Preventing Invalid Size
        if (size<=0)    max_size=100;
        else            max_size = size;

        // Iniators
        front = 0;
        arr = new t[max_size];    //Constructor
        rear = max_size-1;
        length = 0;
    }


    // START EMPTY FUNCTION
    bool isEmpty(){
        return length==0;
    }
    // END EMPTY FUNCTION


    // START EMPTY FUNCTION
    bool isFull(){
        return length==max_size;
    }
    // END EMPTY FUNCTION


    // START ADDITION FUNCTION
    void addQueue(t element){
        if (isFull()) {
            cout << "Invalid Process" << endl;
        }else{
            rear = (rear+1) % max_size;
            arr[rear] = element;
            length++;
        }
    }
    // END ADDITION FUNCTION


    // START DELETION FUNCTION
    void deleteQueue (){
        if(isEmpty()){
            cout<<"Invalid Process"<<endl;
        }else{
            front = (front+1) % max_size;
            --length;
        }
    }
    // END DELETEION FUNCTION


    // START RETURN FRONT FUNCTION
    int frontQueue(){
        assert(!isEmpty());
        return arr[front];
    }
    // END RETURN FRONT FUNCTION


    // START RETURN REAR FUNCTION
    int rearQueue(){
        assert(!isEmpty());
        return arr[rear];
    }
    // END RETURN REAR FUNCTION


    // START PRINTING FUNCTION
    void print(){
        if (!isEmpty()){
            for (size_t i=front;  i!=rear;  i=(i+1)%max_size){
                cout<<arr[i]<<" ";
            }
            cout<<arr[rear];
        }else{
            cout<<"Invalid Process"<<endl;
        }
    }
    // END PRINTING FUNCTION


    // START SEARCH FUNCTION
    int searchQueue(t element){
        int pos = -1;
        if (!isEmpty()){
            for (int i=front; i!=rear; i=(i+1)%max_size){
                if (arr[i]==element){
                    pos = i;
                    return pos;
                }
                if (pos == -1){
                    if (arr[rear] == element){
                        pos = rear;
                        return pos;
                    }
                }
            }
            return pos;         // Is Not Found
        }else{
            cout<<"Invalid Process ... Empty Queue"<<endl;
        }
    }
    // END SEARCH FUNCTION








};








int main() {
    queue<char> q(5);
    q.addQueue('a');
    q.addQueue('b');
    q.addQueue('c');
    q.addQueue('d');
    q.addQueue('e');
    q.addQueue('f');
    q.print();
    cout<<endl;

    q.deleteQueue();
    q.addQueue('J');
    q.print();
    cout<<endl;
    cout<<q.searchQueue('J')<<endl;



    return 0;
}
