#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

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
    bool operator==(const Item& other) const {
        return this->itemName == other.itemName;
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
    void insertMinHeap(Item item) {
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
    void insertMaxHeap(Item item) {
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


                                                                      // < AVL Trees >

class AVLNode {
public:
    Item item;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(Item item) : item(item), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insertNode(AVLNode* node, Item item) {
        if (node == nullptr)
            return new AVLNode(item);

        if (item < node->item)
            node->left = insertNode(node->left, item);
        else if (item > node->item)
            node->right = insertNode(node->right, item);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && item < node->left->item)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && item > node->right->item)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && item > node->left->item) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && item < node->right->item) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNode(AVLNode* root, Item key) {
        if (root == nullptr)
            return root;

        if (key < root->item)
            root->left = deleteNode(root->left, key);
        else if (key > root->item)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->item = temp->item;
                root->right = deleteNode(root->right, temp->item);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && balanceFactor(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrderTraversal(AVLNode* root, vector<Item>& items) {
        if (root != nullptr) {
            inOrderTraversal(root->left, items);
            items.push_back(root->item);
            inOrderTraversal(root->right, items);
        }
    }

    void preOrderTraversal(AVLNode* root) {
        if (root != nullptr) {
            root->item.print();
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void postOrderTraversal(AVLNode* root) {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            root->item.print();
        }
    }

    bool searchNode(AVLNode* root, const Item& item) {
        if (root == nullptr)
            return false;

        if (root->item == item)
            return true;

        if (root->item < item)
            return searchNode(root->right, item);

        return searchNode(root->left, item);
    }

    int getSize(AVLNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + getSize(root->left) + getSize(root->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insertAVL(Item item) {
        root = insertNode(root, item);
    }

    void remove(Item item) {
        root = deleteNode(root, item);
    }

    void displayInOrder() {
        vector<Item> items;
        inOrderTraversal(root, items);
        for (const auto& item : items) {
            item.print();
        }
    }

    void displayByNameAscending() {
        vector<Item> items;
        inOrderTraversal(root, items);
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.itemName < b.itemName;
        });
        for (const auto& item : items) {
            item.print();
        }
    }

    void displayByNameDescending() {
        vector<Item> items;
        inOrderTraversal(root, items);
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.itemName > b.itemName;
        });
        for (const auto& item : items) {
            item.print();
        }
    }

    void displayByPriceAscending() {
        vector<Item> items;
        inOrderTraversal(root, items);
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.price < b.price;
        });
        for (const auto& item : items) {
            item.print();
        }
    }

    void displayByPriceDescending() {
        vector<Item> items;
        inOrderTraversal(root, items);
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.price > b.price;
        });
        for (const auto& item : items) {
            item.print();
        }
    }

    void displayPreOrder() {
        preOrderTraversal(root);
    }

    void displayPostOrder() {
        postOrderTraversal(root);
    }

    bool search(const Item& item) {
        return searchNode(root, item);
    }

    int getSize() {
        return getSize(root);
    }
};






void readItemsMin(istream& i, MinHeap& minHeap) {
    string itemName, category;
    int price;

    while (i >> itemName >> category >> price) {
        Item newItem(itemName, category, price);
        minHeap.insertMinHeap(newItem);
        cout << "Inserted item: ";
        newItem.print();
    }

    if (i.eof()) {
        cout << "End of file reached." << endl;
    } else {
        cerr << "Error reading items from file." << endl;
    }
}



void readItemsMax(istream& i, MaxHeap& maxHeap) {
    string itemName, category;
    int price;

    while (i >> itemName >> category >> price) {
        Item newItem(itemName, category, price);
        maxHeap.insertMaxHeap(newItem);
        cout << "Inserted item: ";
        newItem.print();
    }

    if (i.eof()) {
        cout << "End of file reached." << endl;
    } else {
        cerr << "Error reading items from file." << endl;
    }
}


void readItemsAVL(istream& i, AVLTree& avlTree) {
    string itemName, category;
    int price;

    while (i >> itemName >> category >> price) {
        Item newItem(itemName, category, price);
        avlTree.insertAVL(newItem);
        cout << "Inserted item: ";
        newItem.print();
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

void displayAVLTreeMenu() {
    cout << "1. Add item data" << endl;
    cout << "2. Remove item data" << endl;
    cout << "3. Display the item data normally" << endl;
    cout << "4. Display all the items sorted by their name ascending" << endl;
    cout << "5. Display all the items sorted by their name descending" << endl;
    cout << "6. Display all the items sorted by their prices ascending" << endl;
    cout << "7. Display all the items sorted by their prices descending" << endl;
    cout << "8. Display AVL Tree In-Order Traversal" << endl;
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
                minHeap.insertMinHeap(Item(name, category, price));
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
                maxHeap.insertMaxHeap(Item(name, category, price));
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
void avlTreeMenu(AVLTree& avlTree) {
    int choice;
    string name, category;
    int price;
    do {
        displayAVLTreeMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter item name, category, and price: ";
                cin >> name >> category >> price;
                avlTree.insertAVL(Item(name, category, price));
                break;
            case 2:
                cout << "Enter item name to remove: ";
                cin >> name;
                avlTree.remove(Item(name, "", 0));
                break;
            case 3:
                avlTree.displayInOrder();
                break;
            case 4:
                avlTree.displayByNameAscending();
                break;
            case 5:
                avlTree.displayByNameDescending();
                break;
            case 6:
                avlTree.displayByPriceAscending();
                break;
            case 7:
                avlTree.displayByPriceDescending();
                break;
            case 8:
                avlTree.displayInOrder();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
}


int main() {
    MinHeap minHeap;
    MaxHeap maxHeap;
    AVLTree avlTree;

    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "It's not supported yet." << endl;
                break;
            case 2:
            {
                ifstream inFile("items.txt");
                if (!inFile) {
                    cout << "Error opening file." << endl;
                    break;
                }
                readItemsMin(inFile, minHeap);
                cout << "Items loaded from file." << endl;
                inFile.close();
                minHeapMenu(minHeap);
            }
                break;
            case 3:
            {
                ifstream inFile("items.txt");
                if (!inFile) {
                    cout << "Error opening file." << endl;
                    break;
                }
                readItemsMax(inFile, maxHeap);
                cout << "Items loaded from file." << endl;
                inFile.close();
                maxHeapMenu(maxHeap);
            }
                break;
            case 4:
            {
                ifstream inFile("items.txt");
                if (!inFile) {
                    cout << "Error opening file." << endl;
                    break;
                }
                readItemsAVL(inFile, avlTree);
                cout << "Items loaded from file." << endl;
                inFile.close();
                avlTreeMenu(avlTree);
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
