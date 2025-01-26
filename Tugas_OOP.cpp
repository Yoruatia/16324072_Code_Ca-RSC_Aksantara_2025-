#include <iostream>
#include <string>
#include <vector> // Menambahkan libraries
using namespace std; 

//Membuat Class Contact
class Contact {
private:
    string nama; // deklarasi tipe data untuk nama, daerah, alamat, dan kekuatan
    string daerah;
    string alamat;
    string kekuatan;
    //Memebuat Object Private

public: // Membuat Object Public
    //Constructor

    Contact(string n = "", string d = "", string a = "", string k = "")
        : nama(n), daerah(d), alamat(a), kekuatan(k) {} 

    void setData(string n, string d, string a, string k) { //Assign setdata 
        nama = n;
        daerah = d;
        alamat = a;
        kekuatan = k;
    }
    string getNama() const { return nama; } 
    string getDetails() const { //Tampilan detail tiap kontak
        return "Nama : " + nama + "\nDaerah : " + daerah + 
        "\nAlamat : " + alamat + "\nKekuatan : " + kekuatan + "\n";

    }
};
//Membuat Class PhoneBook
class PhoneBook { 
private: //Membuat Object Private
    Contact contacts[8]; //Membatasi jumlah kontak yang disimpan sebanyak 8
    int count; //Deklarasi count dan next sebagai integer
    int next;
public: //Membuat Object Public
    PhoneBook() : count(0), next(0) {} //Constructor

    void addContact(const Contact& contact) {  //Metode untuk penambahan kontak 
        contacts[next] = contact; 
        next = (next + 1) % 8; //Assign nilai next 
        if (count < 8) count ++; //Membuat kondisi untuk penambahan kontak dan batas kontak
    }
    int getCount() const { //Metode assign variable count
            return count;
        }

    void displayContacts() const {  //Metode penampilan Nomor kontak (1,2,3,4,5,6,7,8)
        if (count ==0 ){ //Conditional pertama jika kontak kosong, syarat, count = 0
            cout << "PhoneBook is empty. \n"; //Display string
            return;
        }
        for (int i = 0; i < count; i++) { //Perulangan untuk nilai count dan pemasukan nomor kontak
            cout << i + 1 << ". " << contacts[i].getNama()<< endl;
        }
    }

    void viewContacts(int index) const {  //Metode Penampilan detail kontak
        if (index < 1 || index > count) { //Conditional batas error kontak
            cout << "Invalid Contact Number. \n"; //syarat, index > 0 
            return;
        }
        cout << contacts[index - 1].getDetails();
        //Menampilkan detail kontak berdasarkan metode getDetails (line 27)
    }
};

int main() { //Membuat tampilan kontak
    PhoneBook phoneBook;
    string command;

    cout << "Welcome to Pak Bell's PhoneBook! \n"; //Pembuka
    while (true) { //Perulangan bersyarat untuk mengulang opsi
        cout << "\nMasukkan Perintah (ADD, SEARCH, EXIT): "; 
        cin >> command; //Meminta input command

        if (command == "ADD") { //Opsi ADD untuk menambahkan dataSet
            string nama, daerah, alamat, kekuatan;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Daerah : ";
            getline(cin, daerah);
            cout << "Masukkan Alamat : ";
            getline(cin, alamat);
            cout << "Masukkan Kekuatan : ";
            getline(cin, kekuatan);
                //Memasukkan input data untuk kontak nomor x
            Contact newContact(nama, daerah, alamat, kekuatan); //Menyimpan data Kontak
            phoneBook.addContact(newContact);
            cout << "Kontak berhasil ditambahkan. \n";
        
        }else if (command == "SEARCH") { //Opsi SEARCH untuk mencari kontak berdasarkan nomor
            if (phoneBook.getCount() == 0) { //Conditional ketika metode getCount return = 0
                cout << "PhoneBook Kosong. \n";
            } else {
                phoneBook.displayContacts();
                int index;
                cout << "Masukkan Nomor Kontak yang ingin dilihat: "; //Meminta nomor kontak
                cin >> index; //Input variable index
                phoneBook.viewContacts(index); //Menampilkan data menggunakan metode viewContacts sesuai index
            }
        } else if (command == "EXIT") { //Opsi EXIT untuk keluar dari buku kontak
            cout << "Goodbye! \n"; 
            break; //Mengakhiri program
        } else {
            cout << "Invalid command. Please try again \n"; //Manajemen resiko input error
        }
    }
    return 0; //End
}
