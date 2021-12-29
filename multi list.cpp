#include <iostream>
using namespace std;

// deklare type mahasiswa
struct mahasiswa{
    string nim;
    string name;
};

// deklare type mahasiswa
struct matkul{
    string kode;
    string value;
};

// type column
struct column{
    matkul *container_col;
    column *next_col = nullptr;
};

// type line
struct line{
    mahasiswa *container_col;
    column *col;
    line *next_line = nullptr;
};

// deklare list utama
struct list{
    line *firstElement; //diambil dari element baris, karena first termasuk element baris
};

void CreateNewList(list *multyList){
    multyList->firstElement = nullptr;
}

void AddFirstLine(list *multyList, string nim, string name){
    line *TempNode;
    TempNode = new line;

    //alokasion
    TempNode->container_col->nim = nim;
    TempNode->container_col->name = name;
    TempNode->col = nullptr;

    // jika list pertama sama dengan null
    if(multyList->firstElement == nullptr){
        TempNode->next_line = nullptr;
    }
    else{
        TempNode->next_line = multyList->firstElement;
    }
    multyList->firstElement = TempNode;
    TempNode = nullptr;
}

void AddFirstColumn(line * multyList, string code, string value){
    column *TempNode;
    TempNode = new column;
    TempNode->container_col->kode = code;
    TempNode->container_col->value = value;

    if(multyList->col == nullptr){
        TempNode->next_col = nullptr;
    }
    else{
        TempNode->next_col = multyList->col;
    }
    multyList->col = TempNode;
    TempNode = nullptr;
}

void ShowDisplay(list *multyList){
    if(multyList->firstElement != nullptr){
        line *copy_line;
        copy_line = multyList->firstElement;
        int i = 1;
        while(copy_line != nullptr){
            cout << "Element Pertama : " << i;
            cout << "NIM  : " << copy_line->container_col->nim;
            cout << "\nNama : " << copy_line->container_col->name;
            column *copy_column;
            copy_column = copy_line->col;
            while(copy_column != nullptr){
                cout << "Kode Kuliah  : " << copy_column->container_col->kode;
                cout << "Nilai kuliah : " << copy_column->container_col->value;
                copy_column = copy_column->next_col;
            }
            cout << "------------------------";
            copy_line = copy_line->next_line;
            i++;
        }
    }
    else{
        cout << "List Empty !";
    }
}

int main(){
    list *multyList;
    multyList = new list;
    
    AddFirstLine(multyList, "A11.2020.12884", "fitri");
    ShowDisplay(multyList);

    return 0;
}


// void AddFirstColumn(line * multyList, string code, string value){
//     column *TempNode;
//     TempNode = new column;
//     TempNode->container_col->kode = code;
//     TempNode->container_col->value = value;

//     if(multyList->col == nullptr){
//         TempNode->next_col = nullptr;
//     }
//     else{
//         TempNode->next_col = multyList->col;
//     }
//     multyList->col = TempNode;
//     TempNode = nullptr;
// }
