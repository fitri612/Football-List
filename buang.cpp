void AddAfterLine(list *ML, string position, string typePlayer){
    line *TempLine;
    TempLine = AllocationLine(ML, typePlayer);

    if(ML->head == nullptr){
        ML->head = TempLine;
    }
    else{
        line *copy;
        copy  = ML->head;
        while(copy != nullptr){
            if(copy->player_Type == position){
                if(copy == ML->tail){
                    TempLine->next_line = nullptr;
                    copy->next_line = TempLine;
                    ML->tail = TempLine;
                }
                else{
                    TempLine->next_line = copy->next_line;
                    copy->prev_line = TempLine;
                    if(copy->next_line != nullptr){
                        copy->next_line->prev_line = TempLine;
                    }
                    copy->next_line = TempLine;
                }
                break;
            }
            copy = copy->next_line;
        }
        
    }
}


// void AddCol(line *TempLine, string name){
//     column * TempCol;
//     TempCol = AllocationCol(TempLine, name);

//     if(TempLine->col == nullptr){
//         TempLine->col = TempCol;
//         TempLine->End_col = TempCol;
//     }
//     else{
//         column * copy;
//         copy = TempLine->col;
//         string posName;
//         cout << "Add data after : ";
//         cin >> posName;
//         while(copy != TempLine->End_col){
//             if(copy->player_name == posName){
//                 if(copy == TempLine->End_col){
//                     TempCol->next_col = nullptr;
//                     copy->next_col = TempCol;
//                     TempLine->End_col = TempCol;
//                 }
//                 else{
//                     TempCol->next_col = copy->next_col;
//                     copy->prev_col = TempCol;
//                     if(copy->next_col != nullptr){
//                         copy->next_col->prev_col = TempCol;
//                     }
//                     copy->next_col = TempCol;
//                 }
//                 break;
//             }
//             copy = copy->next_col;
//         }
//     }
// }



void AddMidfielder(list *ML, string name){
    line *temp = ML->head;
    while(temp != nullptr){
        if(temp->player_Type == "midfielder"){
            line *TempLine = ML->head;
            if(checkPlagiat(ML, name) == false){
                // AddCol(TempLine, name);
                column *TempCol;
                TempCol = AllocationCol(TempLine, name);
                if(TempLine->col == nullptr) {
                    TempLine->col = TempLine->End_col= TempCol;
                } 
                else {
                    column *copy = TempLine->col;
                    string position;
                    cout<<"Tambahkan data setelah apa? "; 
                    cin>>position;
                    while(copy != nullptr) {
                        if(copy->player_name == position) {
                            TempCol->next_col = copy->next_col;
                            TempCol->prev_col = copy;
                            if(copy == TempLine->End_col)
                                TempLine->End_col = TempCol;
                            else
                                copy->next_col->prev_col = TempCol;
                            copy->next_col = TempCol;
                            break;
                        }
                        copy = copy->next_col;
                    }
                }
            }
            else{
                if(checkPlagiat(ML, name) == true)
                    cout << "Sorry, data can't be the same\n";
            }
        }
        else{
            cout << "No midfielder\n";
        }
        temp = temp->next_line;
    }
}