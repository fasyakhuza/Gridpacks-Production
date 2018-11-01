import os
import shutil

exe = 0
sub = 0
def mkDir(dirName):
    if not os.path.isdir(dirName): os.mkdir(dirName)

def main():
    
    # unit of MZp and width is GeV
    MZpList = [3000]
    
    #unit
    mdmList = [1]
    
    print "produce MZp list: ", MZpList
    print
    for MZp in MZpList:
        for mdm in mdmList:
        
            # ZpBaryonic for Z' Mass
            dirName = 'ZpBaryonic_MZp'+str(MZp)+'_MChi'+str(mdm)
        
            mkDir('cards/'+dirName)
            print('create '+dirName)
            shutil.copyfile('cards/ZpBaryonic_template/ZpBaryonic_MZp1000_MChi1_run_card.dat','cards/'+dirName+'/'+dirName+'_run_card.dat')
            shutil.copyfile('cards/ZpBaryonic_template/ZpBaryonic_MZp1000_MChi1_extramodels.dat','cards/'+dirName+'/'+dirName+'_extramodels.dat')
            
            f_proc0 = open('cards/ZpBaryonic_template/ZpBaryonic_MZp1000_MChi1_proc_card.dat','r')
            f_proc1 = open('cards/'+dirName+'/'+dirName+'_proc_card.dat','w')
            for line in f_proc0:
                f_proc1.write(line.replace('ZpBaryonic_MZp1000_MChi1',dirName))
            f_proc0.close()
            f_proc1.close()
            
            f_cust0 = open('cards/ZpBaryonic_template/ZpBaryonic_MZp1000_MChi1_customizecards.dat','r')
            f_cust1 = open('cards/'+dirName+'/'+dirName+'_customizecards.dat','w')
            for line in f_cust0:
                if line.find('MZp') > 0: f_cust1.write(line.replace('MZp',str(MZp)))
                elif line.find('mdm') > 0: f_cust1.write(line.replace('mdm',str(mdm)))
                else: f_cust1.write(line)

            f_cust0.close()
            f_cust1.close()
            command = './gridpack_generation.sh ' + dirName + ' cards/' + dirName
            subcom = './submit_gridpack_generation.sh 12000 12000 1nw ' + dirName + ' cards/' + dirName + ' 2nd'
            print(command)
            if (exe): os.system(command)
            if (sub): os.system(subcom)


if __name__ == "__main__":
    main()
#os.system('cp *.tarball.tar.xz ~/public/gridpackDir')
