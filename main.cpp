#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Item {
public:
    string itemName;
    string category;
    int price;

    Item(string itemName, string category, int price)
            : itemName(itemName), category(category), price(price) {}

    bool operator<(const Item& other) const {
        return this->price < other.price;
    }

    bool operator>(const Item& other) const {
        return this->price > other.price;
    }

    void print() const {
        cout << "Item Name: " << itemName << ", Category: " << category << ", Price: " << price << endl;
    }
};


class MinHeap {
private:
    vector<Item> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(Item item) {
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    void removeMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() const {
        for (const auto& item : heap) {
            item.print();
        }
    }

    void sort() {
        ::sort(heap.begin(), heap.end());
    }
};

class MaxHeap {
private:
    vector<Item> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(Item item) {
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    void removeMax() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display(bool rev = false) const {
        if (!rev)
            for (const auto& item : heap) {
                item.print();
            }
        else
        {
            vector<Item> tempHeap = heap;
            ::sort(tempHeap.rbegin(), tempHeap.rend());
            for (const auto& item : tempHeap) {
                item.print();
            }
        }
    }

    void sort() {
        ::sort(heap.rbegin(), heap.rend());
    }
};


template <typename T>
void readItems(istream& i, T& t) {
    string itemName, category;
    int price;

    while (i >> itemName >> category >> price) {
        t.insert(Item(itemName, category, price));
    }

    if (i.eof()) {
        cout << "End of file reached." << endl;
    } else {
        cerr << "Error reading items from file." << endl;
    }
}



void displayMenu() {
    cout << "1. Binary Search Trees (BST)" << endl;
    cout << "2. Min Heap" << endl;
    cout << "3. Max Heap" << endl;
    cout << "4. AVL Trees" << endl;
    cout << "5. Load Items from a File" << endl;
    cout << "0. Exit" << endl;
}

void displayTreeMenu() {
    cout << "1. Add item data" << endl;
    cout << "2. Remove item data" << endl;
    cout << "3. Display the item data normally" << endl;
    cout << "4. Display all the items sorted by their name ascending" << endl;
    cout << "5. Display all the items sorted by their name descending" << endl;
    cout << "6. Display all the items sorted by their prices ascending" << endl;
    cout << "7. Display all the items sorted by their prices descending" << endl;
    cout << "0. Back to main menu" << endl;
}


void minHeapMenu(MinHeap& minHeap) {
    int choice;
    string name, category;
    int price;
    do {
        displayTreeMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter item name, category, and price: ";
                cin >> name >> category >> price;
                minHeap.insert(Item(name, category, price));
                break;
            case 2:
                minHeap.removeMin();
                break;
            case 3:
                minHeap.display();
                break;
            case 4:
                minHeap.sort();
                minHeap.display();
                break;
            case 5:
                cout << "Display sorted by name descending not supported in Min Heap." << endl;
                break;
            case 6:
                minHeap.sort();
                minHeap.display();
                break;
            case 7:
                cout << "Display sorted by price descending not supported in Min Heap." << endl;
                break;
            case 0:
                cout << "Returning to main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}

void maxHeapMenu(MaxHeap& maxHeap) {
    int choice;
    string name, category;
    int price;
    do {
        displayTreeMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter item name, category, and price: ";
                cin >> name >> category >> price;
                maxHeap.insert(Item(name, category, price));
                break;
            case 2:
                maxHeap.removeMax();
                break;
            case 3:
                maxHeap.display();
                break;
            case 4:
                maxHeap.sort();
                maxHeap.display();
                break;
            case 5:
                maxHeap.sort();
                maxHeap.display(true);
                break;
            case 6:
                cout << "Display sorted by price ascending not supported in Max Heap." << endl;
                break;
            case 7:
                maxHeap.sort();
                maxHeap.display();
                break;
            case 0:
                cout << "Returning to main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}


int main() {
    MinHeap minHeap;
    MaxHeap maxHeap;

    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "It's not supported yet." << endl;
                break;
            case 2:
                minHeapMenu(minHeap);
                break;
            case 3:
                maxHeapMenu(maxHeap);
                break;
            case 4:
                cout << "It's not supported yet." << endl;
                break;
            case 5:
            {
                ifstream inFile("items.txt");
                if (!inFile) {
                    cout << "Error opening file." << endl;
                    break;
                }
                readItems(inFile, minHeap);
                readItems(inFile, maxHeap);
                cout << "Items loaded from file." << endl;
                inFile.close();
            }
                break;
            case 0:
                cout << "Exiting program. Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
