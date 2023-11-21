#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Fungsi untuk menampilkan isi file DNS
void displayFile(const string &filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Gagal membuka file: " << filename << endl;
    }
}

int main()
{
    int mainChoice, subChoice;
    const string dnsDirectory = "source/dns/";

    while (true)
    {
        // Menampilkan menu utama
        cout << "=====================================\n";
        cout << "||                                 ||\n";
        cout << "||          HOLY MIKROTIK          ||\n";
        cout << "||                                 ||\n";
        cout << "=====================================\n";
        cout << "Tool script automation yang memblokir akses ke situs negatif yang ada di Internet,\n";
        cout << "2 pilihan metode: DNS Filtering & Firewall Filtering untuk Router MikroTik.\n";
        cout << "-------------------------------------\n";
        cout << "v1.0 - by Teknik Informatika\n";
        cout << "Universitas Maarif Hasyim Latif Sidoarjo\n";
        cout << "-------------------------------------\n";
        cout << "Team Leader : Achmad Rifan\n";
        cout << "Contributor : \n";
        cout << "M. Rahmad Ramadani | Naila Mufidah Aulia\n";
        cout << "M. Andre Bahtiar | Angga Kurniawan\n";
        cout << "======================================\n\n";
        cout << "Pilih metode filtering yang ingin digunakan:\n";
        cout << "1. DNS Filtering\n";
        cout << "2. Firewall Filtering\n";
        cout << "99. Batalkan program\n";
        cout << "Pilih metode (1/2/99): ";
        cin >> mainChoice;
        cout << "-------------------------------------\n";

        // Menanggapi pilihan metode filtering
        switch (mainChoice)
        {
        case 1:
            // Menampilkan submenu untuk DNS Filtering
            cout << "Pilih penyedia layanan DNS server:\n";
            cout << "1. Cloudflare\n";
            cout << "2. DNSforFamily\n";
            cout << "3. DNS Yandex\n";
            cout << "4. PureDNS\n";
            cout << "5. Quad9\n";
            cout << "6. Vercara\n";
            cout << "0. Kembali ke menu utama\n";
            cout << "Pilih provider (1/2/3/4/5/6/0): ";
            cin >> subChoice;
            cout << "-------------------------------------\n";

            // Menanggapi pilihan submenu DNS Filtering
            if (subChoice >= 1 && subChoice <= 6)
            {
                cout << "Yeay Berhasil.. silahkan copy paste script berikut di Terminal MirkoTik ya\n\n";
                string filename = "source/dns/dns_option" + to_string(subChoice) + ".txt";
                displayFile(filename);
            }
            else if (subChoice == 0)
            {
                cout << "Kembali ke menu utama.\n";
                break;
            }
            else
            {
                cout << "Pilihan tidak valid. Program berhenti.\n";
            }
            return 0;

        case 2:
            // Menampilkan submenu untuk Firewall Filtering
            cout << "Pilih target Firewall Filtering:\n";
            cout << "1. Block Pornography\n";
            cout << "2. Block Gambling\n";
            cout << "0. Kembali ke menu utama\n";
            cout << "Pilih target (1/2/0): ";
            cin >> subChoice;
            cout << "-------------------------------------\n";

            // Menanggapi pilihan submenu Firewall Filtering
            if (subChoice >= 1 && subChoice <= 2)
            {
                cout << "Yeay Berhasil.. silahkan download file rsc berikut dan import ke MikroTik ya\n\n";
                cout << "Silahkan download file rsc MikroTik pada link di bawah ini :\n";
                cout << "https://holymikrotik.com/download/firewall/firewall_option" + to_string(subChoice) + ".rsc\n";
            }
            else if (subChoice == 0)
            {
                cout << "Kembali ke menu utama.\n";
                break;
            }
            else
            {
                cout << "Pilihan tidak valid. Program berhenti.\n";
            }
            return 0;

        case 99:
            cout << "Program berhenti.\n";
            return 0;

        default:
            cout << "Pilihan tidak valid. Program berhenti.\n";
            return 0;
        }
    }

    return 0;
}
