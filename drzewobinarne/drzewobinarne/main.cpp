#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>

#define COUNT  10
using namespace std;
void menu(){
    cout<<"////Obsluga funkcji drzewa binarnego////"<<endl;
    cout<<"1) Dodaj wartosc do drzewa"<<endl;
    cout<<"2) Usun wartosc z drzewa"<<endl;
    cout<<"3) Sprawdz czy wartosc znajduje sie w drzewie"<<endl;
    cout<<"4) Wyswietl Traversale"<<endl;
    cout<<"5) Wyswietl drzewo graficznie"<<endl;
    cout<<"6) Zamknij program"<<endl;
    
}
struct Galaz {
    int wartosc;
    Galaz* lewy;
    Galaz* prawy;
    
};

class DrzewoBinarne {
public:
    
    Galaz* korzen;
    
    DrzewoBinarne() {
        korzen = nullptr;
    }
    
    ~DrzewoBinarne() {
        usunDrzewo(korzen);
    }

    void wstaw(int wartosc) {
        if (korzen == nullptr) {
            korzen = new Galaz;
            korzen->wartosc = wartosc;
            korzen->lewy = nullptr;
            korzen->prawy = nullptr;
        }
        else {
            wstaw(korzen, wartosc);
        }
    }

    void usun(int wartosc) {
        usun(korzen, wartosc);
    }

    
    void preorderTraversal(){
        preorderTraversal(korzen);
        cout<<endl;
    }
    void inorderTraversal() {
            inorderTraversal(korzen);
            cout << endl;
        }
    
    void postorderTraversal() {
            postorderTraversal(korzen);
            cout << endl;
        }
    void usunDrzewo(   Galaz*  galaz) {
        if (    galaz != nullptr) {
            usunDrzewo(galaz->lewy);
            usunDrzewo(galaz->prawy);
            delete galaz;
        }
    }
    
    void wstaw(Galaz* galaz, int wartosc) {
        if (wartosc < galaz->wartosc) {
            if (galaz->lewy != nullptr) {
                wstaw(galaz->lewy, wartosc);
            }
            else {
                galaz->lewy = new Galaz;
                galaz->lewy->wartosc = wartosc;
                galaz->lewy->lewy = nullptr;
                galaz->lewy->prawy = nullptr;
            }
        }
        else {
            if (galaz->prawy != nullptr) {
                wstaw(galaz->prawy, wartosc);
            }
            else {
                galaz->prawy = new Galaz;
                galaz->prawy->wartosc = wartosc;
                galaz->prawy->lewy = nullptr;
                galaz->prawy->prawy = nullptr;
            }
        }
    }

    Galaz* usun(Galaz* galaz, int wartosc) {
        if (galaz == nullptr) {
            return galaz;
        }

        if (wartosc < galaz->wartosc) {
            galaz->lewy = usun(galaz->lewy, wartosc);
        }
        else if (wartosc > galaz->wartosc) {
            galaz->prawy = usun(galaz->prawy, wartosc);
        }
        else {
            if (galaz->lewy == nullptr) {
                Galaz* temp = galaz->prawy;
                delete galaz;
                return temp;
            }
            else if (galaz->prawy == nullptr) {
                Galaz* temp = galaz->lewy;
                delete galaz;
                return temp;
            }

            Galaz* temp = min(galaz->prawy);
            galaz->wartosc = temp->wartosc;
            galaz->prawy = usun(galaz->prawy, temp->wartosc);
        }

        return galaz;
    }

    Galaz* min(Galaz* galaz) {
        Galaz* current = galaz;
        while (current && current->lewy != nullptr) {
            current = current->lewy;
        }
        return current;
    }
    
    
    void postorderTraversal(Galaz* galaz) {
        if (galaz != nullptr) {
            postorderTraversal(galaz->lewy);
            postorderTraversal(galaz->prawy);
            cout << galaz->wartosc << " ";
        }
    }
    void preorderTraversal(Galaz* galaz) {
        if (galaz != nullptr) {
            cout << galaz->wartosc << " ";
            preorderTraversal(galaz->lewy);
            preorderTraversal(galaz->prawy);
        }
    }
    void inorderTraversal(Galaz* galaz) {
        if (galaz != nullptr) {
            inorderTraversal(galaz->lewy);
            cout << galaz->wartosc << " ";
            inorderTraversal(galaz->prawy);
        }
    }
    Galaz* szukaj(int wartosc) {
        return szukaj(korzen, wartosc);
    }
    void printTree(Galaz* galaz, int indent = 0);
    Galaz* szukaj(Galaz* Galaz, int wartosc) {
        if (Galaz == nullptr || Galaz->wartosc == wartosc) {
            return Galaz;
        }

        if (wartosc < Galaz->wartosc) {
            return szukaj(Galaz->lewy, wartosc);
        }

        return szukaj(Galaz->prawy, wartosc);
    }
    Galaz* getRoot() {
        return korzen;
    }
    void rysuj(Galaz* korzen, int spacja)
    {
        // Base case
        if (korzen == NULL)
            return;
     
        
        spacja += COUNT;
     
        
        rysuj(korzen->prawy, spacja);
     
        // Print current node after space
        // count
        cout << endl;
        for (int i = COUNT; i < spacja; i++)
            cout << " ";
        cout << korzen->wartosc << "\n";
     
        
        rysuj(korzen->lewy, spacja);
    }
    void print2D(Galaz* korzen)
    {
        
        rysuj(korzen, 0);
    }
    
};

int main() {
    DrzewoBinarne tree;
    
    tree.wstaw(5);
    tree.wstaw(24);
    tree.wstaw(40);
    tree.wstaw(22);
    tree.wstaw(30);
    tree.wstaw(38);
    menu();
    int wybor;
    std::cin >> wybor;
    while (std::cin.fail()) {
        std::cout << "Wprowadziles bledne dane" << std::endl;
        
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        
        std::cout << "Wprowadz dane ponownie:";
        std::cin >> wybor;
    }
    while (wybor != 6) {
        
        switch (wybor) {
            case 1:{
                int dana;
                cout<<"Podaj wartosc ktora chcesz dodac do drzewa"<<endl;
                cin>>dana;
                tree.wstaw(dana);
                cout<<"Wartosc "<<dana<<" dodana"<<endl;
                break;
            }
            case 2:{
                int dana;
                cout<<"Podaj wartosc ktora chcesz usunac z drzewa"<<endl;
                cin>>dana;
                tree.usun(dana);
                break;
            }
            case 3:{
                int dana;
                cout<<"Podaj wartosc aby sprawdzic czy znajduje sie w drzewie"<<endl;
                cin>>dana;
                Galaz* szukanaWdrzewie = tree.szukaj(dana);
                if (szukanaWdrzewie == nullptr) {
                    cout << "Galaz z wartoscia "<<dana<<" nie znaleziona!" << endl;
                }
                else {
                    cout << "Galaz z wartoscia "<<dana<<" znaleziona" << endl;
                }
                break;
            }
            case 4:{
                cout<<"Inorder traversal: ";
                tree.inorderTraversal();
                cout<<"\n Postorder traversal: ";
                tree.postorderTraversal();
                cout<<"\n Preorder traversal: ";
                tree.preorderTraversal();
                break;
            }
            case 5:{
                cout<<"Drzewo graficznie: ";
                tree.print2D(tree.korzen);
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                menu();
                break;
            }
            
            default:
                    {
                        system("cls");
                        menu();
                        std::cout << "Zostala wprowadzona zla wartosc" << std::endl;


                        break;
                    }
                }
            std::cin >> wybor;
        }
    
        return 0;
    }

