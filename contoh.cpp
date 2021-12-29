#include <iostream>
using namespace std;

// deklare type mahasiswa
struct self{
    string name;
};

// deklare type mahasiswa
struct friends{
    string nameFriends;
};

// type column
struct column{
    friends container_col;
    column *next_col = nullptr;
    int CountColumn = 0;
};

// type line
struct line{
    self container_col;
    column *col;
    line *next_line = nullptr;
    int CountLine = 0;
};

// deklare list utama
struct list{
    line *firstElement; //diambil dari element baris, karena first termasuk element baris
};


void CreateNewList(list *multyList){
    multyList->firstElement = nullptr;
}

void addFirstLine(list *multyList, string name){

    // deklare new node
    line *NewNodeLine;
    NewNodeLine = new line;
    NewNodeLine->container_col.name = name;
    NewNodeLine->col = nullptr;

    if(multyList->firstElement == nullptr){
        NewNodeLine->next_line = nullptr;
    }
    else{
        NewNodeLine->next_line = multyList->firstElement;
    }
    multyList->firstElement = NewNodeLine;
    NewNodeLine = nullptr;
    // NewNodeLine->CountLine++;
}

void AddFirstColumn(line *multyListLine, string friends){
    column *NewNodeColumn;
    NewNodeColumn = new column;
    NewNodeColumn->container_col.nameFriends = friends;

    if(multyListLine->col == nullptr){
        NewNodeColumn->next_col = nullptr;
    }
    else{
        NewNodeColumn->next_col = multyListLine->col;
    }
    multyListLine->col = NewNodeColumn;
    NewNodeColumn = nullptr;
    // NewNodeColumn->CountColumn++;
}

void SHowAll(list *mulyList){

    if(mulyList->firstElement != nullptr){
        line *TempNodeLine;
        TempNodeLine = mulyList->firstElement;

        int i = 1;
        while(TempNodeLine != nullptr){
            cout << "\nElement Ke-" << i;
            cout << "\nName  : " << TempNodeLine->container_col.name;
            // TempNodeColumn = new column;
            column *TempNodeColumn;
            TempNodeColumn = TempNodeLine->col;
            while(TempNodeColumn != nullptr){
                cout << "\nFriend : " << TempNodeColumn->container_col.nameFriends;
                TempNodeColumn = TempNodeColumn->next_col;
            }
            TempNodeLine = TempNodeLine->next_line;
            i++;
        }

    }
    else{
        cout << "null";
    }
}


int main(){

    list *mult;
    mult = new list;

    CreateNewList(mult);
    SHowAll(mult);

    addFirstLine(mult, "fitri");
    AddFirstColumn(mult->firstElement, "vita");
    addFirstLine(mult, "reza");
    AddFirstColumn(mult->firstElement, "indah");
    AddFirstColumn(mult->firstElement, "inkh");
    SHowAll(mult);

    // SHowAll(mult);


}
