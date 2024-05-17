#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class ItemBST {
private:
    struct Item {
        string name;
        string category;
        double price;

        Item(string n, string c, double p) : name(n), category(c), price(p) {}
    };

    struct Node {
        Item data;
        Node* left;
        Node* right;

        Node(Item value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    void addHelper(Node* temp, Item value) {
        if (value.name <= temp->data.name) {
            if (temp->left == nullptr) {
                temp->left = new Node(value);
            } else {
                addHelper(temp->left, value);
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = new Node(value);
            } else {
                addHelper(temp->right, value);
            }
        }
    }

    Node* removeHelper(Node* root, string name) {
        if (root == nullptr) return root;
        if (name < root->data.name)
            root->left = removeHelper(root->left, name);
        else if (name > root->data.name)
            root->right = removeHelper(root->right, name);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* temp = getMinNode(root->right);
                root->data = temp->data;
                root->right = removeHelper(root->right, temp->data.name);
            }
        }
        return root;
    }

    Node* getMinNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    //in order travers
    void inOrder(Node* temp, vector<Item>& items) {
        if (temp == nullptr) return;
        inOrder(temp->left, items);
        items.push_back(temp->data);
        inOrder(temp->right, items);
    }

    void displayItems(const vector<Item>& items) {
        for (const auto& item : items) {
            cout << "Name: " << item.name << ", Category: " << item.category << ", Price: " << item.price << endl;
        }
    }

//    void DestroyBST(Node* temp) {
//        if (temp == nullptr) return;
//        DestroyBST(temp->left);
//        DestroyBST(temp->right);
//        delete temp;
//    }

public:
    void add(string name, string category, double price) {
        Item newItem(name, category, price);
        if (root == nullptr) {
            root = new Node(newItem);
        } else {
            addHelper(root, newItem);
        }
    }

    void remove(string name) {
        root = removeHelper(root, name);
    }

    void displayItemsInOrder() {
        vector<Item> items;
        inOrder(root, items);
        displayItems(items);
    }

    void displayItemsSortedByName(bool ascending = true) {
        vector<Item> items;
        inOrder(root, items);
        if (ascending) {
            sort(items.begin(), items.end(), [](Item a, Item b) { return a.name < b.name; });
        } else {
            sort(items.begin(), items.end(), [](Item a, Item b) { return a.name > b.name; });
        }
        displayItems(items);
    }

    void displayItemsSortedByPrice(bool ascending = true) {
        vector<Item> items;
        inOrder(root, items);
        if (ascending) {
            sort(items.begin(), items.end(), [](Item a, Item b) { return a.price < b.price; });
        } else {
            sort(items.begin(), items.end(), [](Item a, Item b) { return a.price > b.price; });
        }
        displayItems(items);
    }

//    ~ItemBST() {
//        DestroyBST(root);
//    }
};

void showMenu() {
    cout << "Mini-menu:\n";
    cout << "I. Add items\n";
    cout << "II. Remove item data\n";
    cout << "III. Display the item data normally\n";
    cout << "IV. Display all the items sorted by their name ascending\n";
    cout << "V. Display all the items sorted by their name descending\n";
    cout << "VI. Display all the items sorted by their prices ascending\n";
    cout << "VII. Display all the items sorted by their prices descending\n";
    cout << "VIII. Exit\n";
}
//string toLowerWord(string word){
//    string res;
//    for (int i = 0; i <word.size() ; ++i) {
//        res+=word[i];
//    }
//    return res;
//}
int main() {
    ItemBST tree;
    string choice;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        getline(cin, choice);

        if (choice == "VIII" || choice == "viii") {
            break;
        }

        string name, category;
        double price;
        int itemCount;

        if (choice == "I" || choice == "i") {
            cout << "Enter number of items to add: ";
            cin >> itemCount;
            cin.ignore();
            for (int i = 0; i < itemCount; ++i) {
                cout << "Enter item " << i + 1 << " name: ";

                getline(cin, name);

                cout << "Enter item " << i + 1 << " category: ";
                getline(cin, category);
                cout << "Enter item " << i + 1 << " price: ";
                cin >> price;
                cin.ignore();

                tree.add(name, category, price);
            }
        } else if (choice == "II" || choice == "ii") {
            cout << "Enter item name to remove: ";
            getline(cin, name);
            tree.remove(name);
        } else if (choice == "III" || choice == "iii") {
            tree.displayItemsInOrder();
        } else if (choice == "IV" || choice == "iv") {
            tree.displayItemsSortedByName(true);
        } else if (choice == "V" || choice == "v") {
            tree.displayItemsSortedByName(false);
        } else if (choice == "VI" || choice == "vi") {
            tree.displayItemsSortedByPrice(true);
        } else if (choice == "VII" || choice == "vii") {
            tree.displayItemsSortedByPrice(false);
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
