/*
    Programmer  : Dwi Prabowo
    NIM         : A11.2021.13761
    Klpk        : A11.43UG2
*/

#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct stacks
{
    string nama;
    int Nilai;
    stacks *next;
};

stacks *head = NULL, *tail = NULL;
int top = 1;
int Max = 5;

int isEmpty()
{
    if (tail == NULL)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top > Max)
        return 1;
    else
        return 0;
}

void insert_belakang()
{
    if (isFull() == 1)
    {
        cout << "Data Penuh" << endl;
    }
    else
    {
        stacks *baru = new stacks;
        cout << "Masukkan Nama : ";
        cin >> baru->nama;
        cout << "Masukkan Nilai : ";
        cin >> baru->Nilai;
        baru->next = NULL;

        if (isEmpty() == 1)
        {
            head = tail = baru;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
        cout << "Data Masuk\n";
        top++;
    }
}

void hapus_belakang()
{
    stacks *bantu, *hapus;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            hapus = tail;
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            hapus = tail;
            head = tail = NULL;
            delete hapus;
        }
        top--;
    }
    else
    {
        cout << "Stack Kosong" << endl;
    }
}

void tampil()
{
    if (isEmpty() == 1)
    {
        cout << "Stack Kosong" << endl;
    }
    else
    {
        stacks *bantu;
        bantu = head;
        int angka = 1;
        while (bantu != NULL)
        {
            cout << angka << ". " << bantu->nama << " " << bantu->Nilai << endl;
            bantu = bantu->next;
            angka++;
        }
    }
}

int nama_menu()
{
    cout << "======================================================\n";
    cout << "Nama : Dwi Prabowo\n";
    cout << "NIM : A11.2021.13761\n";
    cout << "======================================================\n";
    cout << endl;
    int menu;
    cout << "MENU STACK" << endl;
    cout << "1. Push Data" << endl;
    cout << "2. Pop Data" << endl;
    cout << "3. Tampil Data" << endl;
    cout << "4. Keluar" << endl;

    return menu;
}

int main()
{
    int pilih;
    string menu;

    do
    {
        system("cls");
        tampil();
        cout << endl;
        menu = nama_menu();

        cout << endl
             << "Pilihan anda [1-4] : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            system("cls");
            {
                insert_belakang();
                getch();
                break;
            }
        case 2:
            system("cls");
            {
                hapus_belakang();
                break;
            }
        case 3:
            system("cls");
            {
                cout << "Data Stack" << endl
                     << endl;
                tampil();
                getch();
                break;
            }
        default:
            system("cls");
            {
                cout << "Maaf Pilihan Anda Tidak Tersedia" << endl;
                getch();
                break;
            }
        }
    } while (pilih != 4);
    return 0;
}
