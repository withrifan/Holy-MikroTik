URL="https://raw.githubusercontent.com/StevenBlack/hosts/master/alternates/gambling-porn-only/hosts"
inputFile="source/firewall/blacklist.txt"
processFile1="source/firewall/process1.txt"
processFile2="source/firewall/process2.txt"
processFile3="source/firewall/process3.txt"
processFile4="source/firewall/process4.txt"
outputFile="source/firewall/firewall_block.rsc"
addListName="block-negative"

# Menghapus file output yang lama
rm -f "$outputFile"

# Download file blacklist dengan curl
curl -o "$inputFile" "$URL"

# Menghapus baris ke 1 - 18
sed '1,32d' "$inputFile" > "$processFile1"

# Menghapus 8 karakter pertama di setiap baris
awk '{print substr($0, 9)}' "$processFile1" > "$processFile2"

# Menghitung jumlah baris dalam file
total_lines=$(wc -l < "$processFile2")

# Menghitung jumlah baris yang akan dihapus (8 baris dari bawah)
lines_to_remove=8

# Menghitung jumlah baris yang akan dipertahankan
lines_to_keep=$((total_lines - lines_to_remove))

# Menggunakan perintah head untuk mempertahankan jumlah baris yang sesuai
head -n "$lines_to_keep" "$processFile2" > "$processFile3"

# Menghapus yang bukan domain
grep '\.' "$processFile3" > "$processFile4"

# Membuat address list ke Firewall MikroTik
echo "/ip firewall address-list" >> $outputFile
echo "add list=$addListName comment=negative" >> $outputFile

# Membaca isi file dan menggabungkan baris menjadi format yang diinginkan
while IFS= read -r line; do
  echo "add address=$line list=$addListName" >> "$outputFile"
done < "$processFile4"

# Menerapkan address list ke Firewall Filter
echo "/ip firewall filter add chain=forward protocol=tcp dst-address-list=$addListName action=drop comment=block-negative" >> $outputFile

# Mengapus process file agar ketika dijalankan codenya lagi bisa terupdate listnya
rm -f "$inputFile"
rm -f "$processFile1"
rm -f "$processFile2"
rm -f "$processFile3"
rm -f "$processFile4"

# Tampilkan informasi bahwa program berhasil
echo "Yeay.. File konfigurasi MikroTik sudah selesai dibuat: $outputFile"
