
# ESP32 Web Server untuk Deteksi Gerakan dan Penghitung Orang

Proyek ini membuat server web menggunakan mikrokontroler ESP32 untuk memantau gerakan menggunakan dua sensor PIR. Sensor ini mendeteksi orang yang masuk dan keluar ruangan, dan sistem menghitung jumlah orang yang saat ini berada di dalam ruangan. Server web menampilkan informasi ini secara real-time di halaman web.

## Daftar Isi
- [Fitur](#fitur)
- [Perangkat Keras yang Diperlukan](#perangkat-keras-yang-diperlukan)
- [Perangkat Lunak yang Diperlukan](#perangkat-lunak-yang-diperlukan)
- [Diagram Pemasangan](#diagram-pemasangan)
- [Instalasi](#instalasi)
- [Penggunaan](#penggunaan)
- [Kustomisasi](#kustomisasi)
- [Lisensi](#lisensi)

## Fitur
- Pemantauan real-time gerakan yang terdeteksi oleh sensor PIR.
- Menghitung jumlah orang di dalam ruangan.
- Antarmuka server web yang menampilkan jumlah orang saat ini dan status gerakan.
- Notifikasi ketika kapasitas maksimum ruangan tercapai.

## Perangkat Keras yang Diperlukan
- Mikrokontroler ESP32
- 2 x Sensor PIR
- 2 x LED
- Breadboard dan kabel jumper

## Perangkat Lunak yang Diperlukan
- [Arduino IDE](https://www.arduino.cc/en/software) dengan dukungan board ESP32
- Browser web (untuk mengakses server web)

## Diagram Pemasangan
1. **Sensor PIR 1 (Masuk)**
   - VCC ke ESP32 3.3V
   - GND ke ESP32 GND
   - OUT ke ESP32 Pin 13

2. **Sensor PIR 2 (Keluar)**
   - VCC ke ESP32 3.3V
   - GND ke ESP32 GND
   - OUT ke ESP32 Pin 4

3. **LED 1 (Indikator Masuk)**
   - Kaki positif ke ESP32 Pin 12
   - Kaki negatif ke GND (melalui resistor)

4. **LED 2 (Indikator Keluar)**
   - Kaki positif ke ESP32 Pin 5
   - Kaki negatif ke GND (melalui resistor)

## Instalasi
1. Instal [Arduino IDE](https://www.arduino.cc/en/software).
2. Instal paket board ESP32 melalui Arduino IDE:
   - Buka `File > Preferences` dan tambahkan URL berikut ke "Additional Board Manager URLs": `https://dl.espressif.com/dl/package_esp32_index.json`
   - Buka `Tools > Board > Boards Manager`, cari "ESP32", dan instal.
3. Klon repositori ini atau salin kodenya ke dalam Arduino IDE Anda.
4. Unggah kode ke ESP32 Anda.

## Penggunaan
1. Setelah mengunggah kode ke ESP32, buka Serial Monitor dengan baud rate 115200 untuk melihat alamat IP yang diberikan ke ESP32 Anda.
2. Hubungkan ke server web ESP32 dengan memasukkan alamat IP tersebut di browser web.
3. Antarmuka web akan menampilkan jumlah orang yang saat ini berada di ruangan dan menunjukkan apakah ada gerakan yang terdeteksi di pintu masuk atau keluar.

## Kustomisasi
- **Jumlah Maksimum Orang:** Jumlah maksimum orang yang diizinkan di dalam ruangan dapat disesuaikan dengan mengubah variabel `maxPeopleCount`.
- **Tingkat Penyegaran Halaman Web:** Tingkat penyegaran halaman web dapat dimodifikasi dengan mengubah baris `content += "<meta http-equiv=\"refresh\" content=\"1\" />";` dalam fungsi `HTMLControl()`.

## Lisensi
Proyek ini dilisensikan di bawah Lisensi MIT. Lihat file [LICENSE](LICENSE) untuk detailnya.

