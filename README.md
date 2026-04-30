# Blockchain Core Algorithm Implementation (C++)

Bu proje, temel bir blok zinciri (blockchain) veri yapısının ve doğrulama algoritmasının C++ dili kullanılarak nesne yönelimli programlama (OOP) prensipleriyle uygulanmasıdır. Projenin odağı, verilerin değişmezliğini (**immutability**) sağlayan çekirdek mantığı simüle etmektir.

##  Algoritma Mimarisi

Sistem iki temel bileşen üzerine kuruludur:

### 1. Block Yapısı
Her blok, zincirin bir halkasını temsil eder ve şu verileri içerir:
* **previousHash:** Bir önceki bloğun benzersiz imzası.
* **data:** Blok içinde saklanan sayısal veri.
* **currentHash:** Bloğun içeriği (veri + önceki hash) kullanılarak üretilen dijital mühür.

### 2. Verification (Doğrulama) Mekanizması
Algoritma, zincir güvenliğini sağlamak için iki aşamalı bir denetim yapar:
1. **Zincirleme Kontrolü:** Her bloğun `previousHash` değeri, bir önceki bloğun `currentHash` değeriyle uyuşuyor mu?
2. **Bütünlük Kontrolü:** Blok içindeki veri tekrar hashlendiğinde, kayıtlı olan imza ile eşleşiyor mu? (Bu adım, verinin gizlice değiştirilmesini engeller).

##  Siber Saldırı ve Veri Manipülasyon Testi
Proje içerisinde algoritmanın kararlılığını test eden bir senaryo bulunmaktadır:
* Zincire geçerli bloklar eklenir.
* Mevcut bir bloğun verisi manuel olarak manipüle edilir.
* `dogrula()` fonksiyonu, verinin değiştiğini ancak mühürün eski kaldığını anında tespit ederek **ALARM** durumuna geçer.

##  Kullanım
Kodun derlenmesi için standart bir C++ derleyicisi yeterlidir.

---
