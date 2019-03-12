# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow

# Executables
myasm=asm
zazasm=ressources/vm_champs/asm

for f in `find . -type f -name "*.s"`
do
	## Stocke le nom sans path ni extension
	file=`echo $f | rev | cut -d \/ -f 1 | cut -c 3- | rev`
	## Commpile le champion avec l'asm de zaz et stocke la sortie dans un fichier
	./$zazasm $f >> test/result/$file
	if [ -f ${f%.s}.cor ]; then
		hexdump -Cv ${f%.s}.cor >> test/zazasm/dump/$file
		mv ${f%.s}.cor test/zazasm/
	fi
	## Commpile le champion avec mon asm et stocke la sortie dans un fichier
	./$myasm $f >> test/result/$file
	if [ -f ${f%.s}.cor ]; then
		hexdump -Cv ${f%.s}.cor >> test/myasm/dump/$file
		mv ${f%.s}.cor test/myasm/
	fi
	## Test l'existence des 2 fichiers .cor puis fais un diff
	if [ -f test/zazasm/dump/$file ] && [ -f test/myasm/dump/$file ]; then
		diff test/zazasm/dump/$file test/myasm/dump/$file >> test/result/$file
	fi
	## Compare les resultats
	if [ -f test/zazasm/${file}.cor ] && [ -f test/myasm/${file}.cor ]; then
		echo "${Green}$f ✅${Reset}"
	elif [ -f test/zazasm/${file}.cor ]; then
		echo "${Red}$f ❌${Reset}"
	else
		echo "${Yellow}$f ⚠️${Reset}"
		# echo "${Green}$file ✅${Reset}"
	fi
done