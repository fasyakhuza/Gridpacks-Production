#!/bin/bash

file_name=$(find job_ZpBaryonic_MZp*.tar.xz/cmsgrid_final.lhe)

for i in $file_name;do
	flag_mzp=true
	flag_mdm=true 
	flag_LHAID=true
	flag_gq=true
	flag_gz=true
	flag_WEIGHTID_1_9=true
	flag_WEIGHTID_879=true
	flag_WEIGHTID_777_877=true
	flag_final=true
	mzp_filename=$(find $i|cut -d '_' -f 3 | tr -d 'MZp')
	mdm_filename=$(find $i|cut -d '_' -f 4 | tr -d 'MChi')	
	mzp_find=$(grep "mzp" $i|tr -s ' '|cut -d ' ' -f 3)	
	mdm_find=$(grep "mdm" $i|tr -s ' '|cut -d ' ' -f 3)
	gq_find=$(grep "# gq" $i|tr -s ' '|cut -d ' ' -f 3)	
	gz_find=$(grep "# gz" $i|tr -s ' '|cut -d ' ' -f 3)

	res1=$(awk 'BEGIN{if ('$mzp_filename' == '$mzp_find') print 1; else print 0}')
	if [ $res1 != 1 ]; then
			flag_mzp=false
			
		fi
	
	echo "MZp"$mzp_filename"="$mzp_find"="$flag_mzp
	
	res2=$(awk 'BEGIN{if ('$mdm_filename' == '$mdm_find') print 1; else print 0}')
	if [ $res2 != 1 ]; then
			flag_mdm=false

		fi

	echo "MChi"$mdm_filename"="$mdm_find"="$flag_mdm
	
	getLHAID=$(grep "lhaid" $i|cut -d '=' -f 1)
	if [ $getLHAID != 315200 ]; then 
			flag_LHAID=false
	fi
	echo "LHAID="$getLHAID"="$flag_LHAID

	res3=$(awk 'BEGIN{if ('$gq_find' == '0.25') print 1; else print 0}')
	if [ $res3 != 1 ]; then
			flag_gq=false
	fi
	echo "gq="$gq_find"="$flag_gq

	res4=$(awk 'BEGIN{if ('$gz_find' == '$mzp_find') print 1; else print 0}')
	if [ $res4 != 1 ]; then
			flag_gz=false
	fi
	echo "gz="$gz_find"="$flag_gz

	for j in {1..9};do
		get_WEIGHTID_1_9=$(grep '<weight id="'$j'"' $i|cut -d '"' -f 8)
		if [ $get_WEIGHTID_1_9 != 315200 ]; then
			flag_WEIGHTID_1_9=false
		fi
	echo "weight_id_"$j"="$get_WEIGHTID_1_9"="$flag_WEIGHTID_1_9
	done	
	
	for k in {777..877};do
		get_WEIGHTID_777_877=$(grep '<weight id="'$k'"' $i|cut -d '"' -f 8)
		g=$((314423+$k))
		if [ $get_WEIGHTID_777_877 != $g ]; then 
			flag_WEIGHTID_777_877=false
		fi
		echo "weight_id_"$k"="$get_WEIGHTID_777_877"="$flag_WEIGHTID_777_877
	done

	get_WEIGHTID_879=$(grep '<weight id="879"' $i|cut -d '"' -f 8)
        if [ $get_WEIGHTID_879 != 263400 ]; then
                        flag_WEIGHTID_879=false
        fi
        echo "weight_id_879="$get_WEIGHTID_879"="$flag_WEIGHTID_879

	if [ $flag_mzp = 'true' ] && [ $flag_mdm = 'true' ] && [ $flag_LHAID = 'true' ] && [ $flag_gq = 'true' ] && [ $flag_gz = 'true' ] && [ $flag_WEIGHTID_1_9 = 'true' ] && [ $flag_WEIGHTID_879 = 'true' ] && [ $flag_WEIGHTID_777_877 = 'true' ]; then
		echo "MZp"$mzp_filename"_MChi"$mdm_filename"_file"='true'
		echo "=================================================================="
	else
		echo "MZp"$mzp_filename"_MChi"$mdm_filename"_file"='false'
		echo "=================================================================="
	fi   
done
