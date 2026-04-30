#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Block {
public:
    string previousHash;
    int sensorVerisi;
    string currentHash;

    Block(int veri, string oncekiHash) {
        sensorVerisi = veri;
        previousHash = oncekiHash;
        currentHash = generateHash(veri, oncekiHash);
    }

    string generateHash(int data, string prev) {
        return "[H" + to_string(data) + prev + "]";
    }
};

class Blockchain {
public:
    vector<Block> chain;

    Blockchain() {
        chain.push_back(Block(0, "Baslangic"));
    }

    void yeniVeriEkle(int veri) {
        string sonMuhur = chain.back().currentHash;
        chain.push_back(Block(veri, sonMuhur));
        cout << "Veri Sisteme Islendi: " << veri<<"\n";
        cout << "Olusan Yeni Muhur: " << chain.back().currentHash << "\n";
        cout << "\n";
    }

    bool dogrula() {
        
        for (int i = 1; i < chain.size(); i++) {
            if (chain[i].previousHash != chain[i - 1].currentHash) {
                return false;
            }



            if (chain[i].currentHash != chain[i].generateHash(chain[i].sensorVerisi, chain[i].previousHash)) {
                return false; // Veri değişmiş ama mühür eski kalmış! Yakaladık!
            }
        }
        return true; 
    }
}; 
int main() {
    Blockchain otonomSistem;

    cout << "--- Otonom Sistem Baslatildi (Blockchain Aktif) ---" ;

    otonomSistem.yeniVeriEkle(450);
    otonomSistem.yeniVeriEkle(510);
    otonomSistem.yeniVeriEkle(490);

    if (otonomSistem.dogrula()) {
        cout << ">>> SISTEM GUVENLI: Verilerde bozulma yok." ;
    }

    cout << "\n--- DIKKAT: Veritabanina siber saldiri yapiliyor! ---"<<"\n";
    otonomSistem.chain[1].sensorVerisi = 999;

    if (otonomSistem.dogrula() == false) {
        cout << ">>> ALARM: Veri Manipulasyonu Tespit Edildi! Zincir koptu."<<"\n";
    }
    else {
        cout << ">>> KRITIK GUVENLIK ACIGI: Veri manipule edildi ama sistem bunu tespit edemedi!";
    }

    cout << "\nProgram sonlandiriliyor..." << endl;
    return 0;
} 