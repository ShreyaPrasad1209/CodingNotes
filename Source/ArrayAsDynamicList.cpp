//Initialize with minimum size of element, doubles at every size increase requirement
//Insert or remove element at any position
//Specify data type for list
#include <iostream>

using namespace std;

template<typename T>
class DynamicArray
{
private:
    T* array;
    int count;
    int size;

    void resize()
    {
        size *= 2;
        T* tempArray = new T[size];
        for(int i = 0; i < count - 1; i++)
            tempArray[i] = array[i];
        delete[] array;
        array = tempArray;
    }

public:
    DynamicArray(int startSize = 1) :
        count(0), size(startSize)
    {
        array = new T[size];
    }

    void PushBack(T value)
    {
        count++;
        if(size < count)
            resize();
        array[count - 1] = value;
    }

    T Top() const
    {
        return array[count - 1];
    }

    void PopBack()
    {
        count--;
    }

    void Insert(T value, int index)
    {
        count++;
        if(size < count)
            resize();
        
        for(int i = index + 1; i < count; i++)
            array[i] = array[i - 1];
        array[index] = value;
    }

    void Remove(int index)
    {        
        for(int i = index; i < count - 1; i++)
            array[i] = array[i + 1];

        count--;
    }

    void PrintElements() const
    {
        for(int i = 0; i < count; i++)
            cout << array[i] << " ";
        cout << endl;
    }

    int Size() const
    {
        return count;
    }
    
    ~DynamicArray()
    {
        delete[] array;
    }
};

int main()
{
    DynamicArray<int> arr(1);
    arr.PushBack(5);
    arr.PushBack(9);
    arr.PushBack(12);
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(11);
    arr.PrintElements();
    arr.PopBack();
    arr.PrintElements();
    arr.Remove(1);
    arr.PrintElements();
    arr.Insert(8, 3);
    arr.PrintElements();
    cout << arr.Size() << endl;
    cout << arr.Top() << endl;

    DynamicArray<char> arr(5);
    arr.PushBack('A');
    arr.PushBack('N');
    arr.PushBack('K');
    arr.PushBack('I');
    arr.PushBack('T');
    arr.PrintElements();
    int size = arr.Size();
    for(int i=0; i<size; i++)
    {
        cout << arr.Top() << " ";
        arr.PopBack();
    }

    //Best way to reverse will be to start swapping from beginning to the end
    //ANKIT = TNKIA = TIKNA = TIKNA

    return 0;
}