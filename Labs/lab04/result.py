import subprocess
import re
out = subprocess.getoutput("./runtests.1")
res = out.split('end')[:-1]
for s in res:
    line = s.split("\n")
    line.remove("")
    title = line[0]
    line1 = line[1].split(",")
    Nb = int(re.findall(r'\d+',line1[2])[0])
    line2 = line[2].split(",")
    Nbs = int(re.findall(r'\d+',line2[2])[0])
    result=int((Nbs-Nb)/(5000*4/3))
    print(title)
    print("Average comparsion: "+str(result))
  
    

    
#print(res)
#print(out)