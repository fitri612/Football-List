#include<iostream>
#include<string>

#define LOG(x) std::cout << x << std::endl;

typedef std::string str;
typedef unsigned int u32;

struct Child {

    private:

        struct Node {

            str data;
            struct Node* next;

            Node(void) {}

            // overloading
            Node(str& data) {

                this->data = data;
                this->next = nullptr; 
            }
            
            ~Node() {}
        };

        struct Node* head;
        struct Node* tail;

        u32 dataCount;

    public:

        Child(void) {

            head = nullptr;
            tail = nullptr;
            dataCount = 0;
        } // create

        ~Child() {}

        // like shift
        void push(str data) {

            struct Node* node;
            struct Node* swap;
            node = new Node(data); // instant
            swap = nullptr;

            if (head == nullptr) {

                head = node;
                tail = node;

            } else {

                swap = head;
                head = node;
                node->next = swap;

            }

            dataCount += 1;
        }

        int size(void) {

            return dataCount;
        }
        
        void push_back(str data) {}
        
        
        void display(void) {

            struct Node* node;
            node = head;

            if (dataCount > 0) {
                for (u32 i = 0; i < dataCount; i++) {

                    str context;
                    context = "child: ";
                    context += std::to_string(i);
                    context += " data: ";
                    context += node->data;

                    LOG(context)

                    node = node->next;
                }
            }
        }

    // pub
};

struct Parent {

    private:

        struct Node {

            struct Child data;
            struct Node* next;

            Node(void) {}

            // overloading
            Node(struct Child& data) {

                this->data = data;
                this->next = nullptr; 
            }
            
            ~Node() {}
        };

        struct Node* head;
        struct Node* tail;

        u32 dataCount;

    public:

        Parent(void) {

            head = nullptr;
            tail = nullptr;
            dataCount = 0;
        } // create

        ~Parent() {}

        // like shift
        void push(struct Child& data) {

            struct Node* node;
            struct Node* swap;
            node = new Node(data); // instant
            swap = nullptr;

            if (head == nullptr) {

                head = node;
                tail = node;

            } else {

                swap = head;
                head = node;
                node->next = swap;

            }

            dataCount += 1;
        }

        int size(void) {

            return dataCount;
        }

        void push_back(struct Child& data) {

            struct Node* node;
            struct Node* swap;
            node = new Node(data); // instant
            swap = nullptr;

            if (head == nullptr) {

                head = node;
                tail = node;

            } else {

                tail->next = node;
                tail = node;

            }

            dataCount += 1;
        }
        
        
        void display(void) {

            struct Node* node;
            node = head;

            if (dataCount > 0) {
                for (u32 i = 0; i < dataCount; i++) {

                    str context;
                    context = "parent: ";
                    context += std::to_string(i);

                    LOG(context)

                    struct Child& x = node->data;
                    x.display();
                    node = node->next;
                }
            }
        }

    // pub
};

int main(const int argc, const char** argv) {

    (void)argc;
    (void)argv;

    Parent parent;
    Child child_0;
    Child child_1;
    Child child_2;

    child_0.push("udin");
    child_0.push("slamet");
    child_0.push("ayu");
    // LOG(child_0.size())
    
    parent.push_back(child_0);

    child_1.push("vivo");
    child_1.push("oppo");
    child_1.push("realme");
    // LOG(child_1.size())

    parent.push_back(child_1);

    child_2.push("aji");
    child_2.push("angga");
    child_2.push("lemon");
    // LOG(child_2.size())

    parent.push_back(child_2);

    parent.display();

    return EXIT_SUCCESS;
}