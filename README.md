# SmartScheduler-DAA
This repository to fulfil Mid Exam of DAA 

Developed by : 
Sulaiman Rasyid Dinitra Aziz - 01085240014


Proyek SmartScheduler bertujuan merancang dan mengimplementasikan mekanisme penjadwalan untuk satu mesin (single CPU cluster) yang menerima banyak job dengan processing time dan deadline masing‑masing. 

Tujuan utama:

1.Meminimalkan total completion time (∑Cᵢ)

2.Memaksimalkan jumlah job yang selesai tepat waktu (meet deadline)

Untuk project ini saya menggunakan pendekatan Greedy hybrid: Earliest Deadline First (EDF) + tie-breaker Shortest Job First (SJF).

yang dimana pendekatan ini mengurutkan job berdasarkan deadline (terkecil → terbesar), bila deadline sama gunakan processing time terkecil terlebih dahulu. Pendekatan ini memberikan keseimbangan yang baik antara performa (banyak job yang selesai on‑time) dan efisiensi komputasi (skala besar).

Cara menjalankan program ini adalah dengan menggunakan Visual Studio, lalu buat project baru dan tambahkan src/main.cpp .

