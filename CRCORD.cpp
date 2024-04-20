#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;

// ESTRUCTURA TESTER.
struct tester {
    string name;
    string team;
    
};

struct testerVacation {
    string name;
    string vacation;
};

//MAIN MENU
int showMainMenu() {
    int option;
    cout << " " << endl;
    cout << "1. Mostrar Equipos" << endl;
    cout << "2. Console Preparation" << endl;
    cout << "3. Team Vacation" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecciona una opcion: " << endl;
    cin >> option;
    cout << endl;
    return option;
}
//MAIN MENU


// Función para mostrar los equipos
void teamVacation() {
    ifstream vacation("vacation.txt");
    if (!vacation) {
        cerr << "No se pudo abrir el Archivo, Verifica la ruta o la existencia del Archivo." << endl;
        return;
    }

    string linea;
    while (getline(vacation,linea)) {
        stringstream ss(linea);
        string nombre,vacation;
        getline(ss, nombre, ',');
        getline(ss, vacation, ',');
        cout << "Nombre : " << nombre << endl << "Vacation : " << vacation;
        cout << endl;
    }

    vacation.close();
}

void team() {
    ifstream datos("data.txt");
    if (!datos) {
        cerr << "No se pudo abrir el Archivo, Verifica la ruta o la existencia del Archivo." << endl;
        return;
    }

    string linea;
    while (getline(datos,linea)) {
        stringstream ss(linea);
        string nombre,team;
        getline(ss, nombre, ',');
        getline(ss, team, ',');
        cout << "Nombre : " << nombre << endl << "Team : " << team << endl;
        cout << "----------" << endl;
    }

    datos.close();
}


void asignarTitulo()
{
    string title, team;

    cin.ignore();
    cout << "Nombre del titulo: " << endl;
    getline(cin, title);
    cout << endl;

    cout << "Ingrese la cantidad de Leads: " << endl;
    int leads;
    cin >> leads;
    cout << endl;

    cout << "Ingrese la cantidad de Testers: " << endl;
    int tester;
    cin >> tester;
    cout << endl;

    cout << "Cual equipo sera asignado: " << endl;
    cin >> team;
    cout << endl;

    vector<string> titleInfo;
    titleInfo.push_back("Title Name: " + title);
    cout << endl;

    for (int  i = 0; i < leads; i++)
    {
        string leadName;
        cout << "Ingrese el nombre del Lead: " << endl;
        cin >> leadName;
        titleInfo.push_back("Lead: " + leadName);

    }

    for (int  i = 0; i < tester; i++)
    {
        string testerName;
        cout << "Ingrese el nombre del Tester: " << (i + 1) << ";" << endl;
        cin >> testerName;
        titleInfo.push_back("Tester: " + testerName);

    }

    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
    cout << "TEAM" << team << endl;
    for (const auto& info : titleInfo) 
    {
        cout << info << endl;
    }
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << "\n";
    
    
}

int main(int argc, char const *argv[]) {
    int option = 0;
    while (option != 5) {
        option = showMainMenu(); // Mostrar el menú y obtener la opción del usuario

        switch (option) {
            case 1:
                team();
                break;

            case 2:
                asignarTitulo();
                break;

            case 3:
                teamVacation();
                break;

            default:
                break;
        }
    }

    return 0;
}