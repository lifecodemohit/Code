def makeHisto(string):
	file=open("histo.r","wt")
	file.write(string)
	file.close
def makeFreq(string):
	file=open("freq.r","wt")
	file.write(string)
	file.close
def makeStyleSheet(size, shade):
	file=open("style.css", "wt")
	file.write("""body {background-color: #fff}
	
	h20  { color:"""+shade[0]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[0] +"""; align="justify"
	}
	h21  { color: """+shade[1]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[1] +""";
	}
	h22  { color: """+shade[2]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[2] +""";
	}
	h23  { color: """+shade[3]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[3]+""";
	}
	h24  { color: """+shade[4]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[4]+""";
	}
	h25  { color: """+shade[2]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[2]+""";
	}
	h26  { color:"""+shade[6]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[6]+""";
	}
	h7  { color: """+shade[7]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[7]+""";
	}
	h8  { color: """+shade[8]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[8]+""";
	}
	h9  { color: """+shade[9]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[9]+""";
	}
	h10  { color: """+shade[10]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[10]+""";
	}
	h11 { color: """+shade[11]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[11]+""";
	}
	h12  { color: """+shade[12]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[12]+""";
	}
	h13  { color: """+shade[13]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[13]+""";
	}
	h14  { color: """+shade[14]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[14]+""";
	}
	h15  { color: """+shade[15]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[15]+""";
	}
	h16  { color: """+shade[16]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[16]+""";
	}
	h17  { color: """+shade[17]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[17]+""";
	}
	h18  { color: """+shade[18]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[18]+""";
	}
	h19  { color: """+shade[19]+""";
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[19]+""";
	}
	""")
	file.close()
def makeHomePage(word,size):
	file=open("homepage.html", "wt")
	name = "PnS assignment1"
	file.write("""<!DOCTYPE HTML>
	<html>
	<head>
	<title>""" + name + """'s Home Page</title>
	<link rel="stylesheet" href="style.css" type="text/css"/>
	</head>
	<body>
	<h20> """+word[0]+""" </h20>
	<h21> """+word[1]+""" </h21>
	<h22> """+word[2]+""" </h22>
	<h23> """+word[3]+""" </h23>
	<h24> """+word[4]+""" </h24>
	<h25> """+word[5]+""" </h25>
	<h26> """+word[6]+""" </h26>
	<h7> """+word[7]+""" </h7>
	<h8> """+word[8]+""" </h8>
	<h9> """+word[9]+""" </h9>
	<h10> """+word[10]+""" </h10>
	<h11> """+word[11]+""" </h11>
	<h12> """+word[12]+""" </h12>
	<h13> """+word[13]+""" </h13>
	<h14> """+word[14]+""" </h14>
	<h15> """+word[15]+""" </h15>
	<h16> """+word[16]+""" </h16>
	<h17> """+word[17]+""" </h17>
	<h18> """+word[18]+""" </h18>
	<h19> """+word[19]+""" </h19>
	</body>
	</html>""")
	file.close()
	
import string
import urllib
from bs4 import BeautifulSoup
import re
import os
from unidecode import unidecode

link = ["http://dblp.org/search/index.php#query=author:anil_k_jain:&qp=H1.536:W1.1:F1.4:F2.4:F3.4:F4.4","http://dblp.org/search/index.php#query=author:thomas_s_huang:&qp=H1.817:W1.1:F1.4:F2.4:F3.4:F4.4","http://dblp.org/search/index.php#query=author:rama_chellappa:&qp=H1.513:W1.1:F1.4:F2.4:F3.4:F4.4"] 
for i in range(3):
	print "website", i+1, link[i]
x=0
while x not in range(1,4):
	x = input("Enter your choice 1 2 or 3: ")
print "Instructions:\n1.It will generate the word cloud(20 most frequent words) and will run as an html file.\n2.Please make sure that html file opens in a browser instead of a text file.\n3.Word with the maximum frequency will be largest in size and lightest in shade.\n4. Names are removed from the content\nLoading..."

regex = ur"author\:(.+?)\:\&+?"
author = re.findall(regex,link[x-1])
z = "http://dblp.org/search/api/?q=ce:author:" + author[0] + ":*&h=1000&c=4&f=0&format=xml"
b = urllib.urlretrieve(z, "test.txt")


content =""
f = open("test.txt", "r")
for line in f:
	if "title" in line:
		soup = BeautifulSoup(line)
		content+=soup.title.contents[-1].strip('- :,.')
f.close()
content =content.encode('ascii', 'ignore')

f = open("test.txt","w")
f.close()
f = open("test.txt","a")

for i in content:
	f.write(i)
f.close()
	
fp=open("test.txt", "r")
a = dict({})
stop = ['i', '','me', 'my', 'myself', 'we', 'our', 'ours', 'ourselves', 'you', 'your', 'yours', 'yourself', 'yourselves', 'he', 'him', 'his', 'himself', 'she', 'her', 'hers', 'herself', 'it', 'its', 'itself', 'they', 'them', 'their', 'theirs', 'themselves','what', 'which', 'who', 'whom', 'this', 'that', 'these', 'those', 'am', 'is', 'are','was', 'were', 'be', 'been', 'being', 'have', 'has', 'had', 'having', 'do', 'does','did', 'doing', 'a', 'an', 'the', 'and', 'but', 'if', 'or', 'because', 'as', 'until', 'while', 'of', 'at', 'by', 'for', 'with', 'about', 'against', 'between', 'into','through', 'during', 'before', 'after', 'above', 'below', 'to', 'from', 'up', 'down','in', 'out', 'on', 'off', 'over', 'under', 'again', 'further', 'then', 'once', 'here','there', 'when', 'where', 'why', 'how', 'all', 'any', 'both', 'each', 'few', 'more','most', 'other', 'some', 'such', 'no', 'nor', 'not', 'only', 'own', 'same', 'so','than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'should', 'now']

for line in fp:
	word=line.split()
	for i in range(len(word)):
		word = [s.translate(None, string.punctuation) for s in word]
			
		word[i] = word[i].lower()
		if word[i] not in stop:
			if word[i] in a.keys():
				a[word[i]]+=1
			else:
				a[word[i]]=1

freq = a.values()
freq.sort()
n = len(freq)
max = freq[n-1]
top = []
j = 1
final = ({})
for i in range(n-20,n):
	top.append(freq[i])
for k,v in a.items():
	if v in top:
		final[k] = v
		print j,k,v
		j+=1
fp.close()	

word = []
size = []
shade=[]
for k,v in final.items():
	size.append(v)
	word.append(k)
	shade.append(v)
for i in range(len(size)):
	size[i] = size[i]
	size[i] = str(size[i])	
	size[i] += "px"
for i in range(len(shade)):
	p = str(shade[i]*max/100)
	if len(p)==2:
		shade[i]="#"+p + "0824"
	elif len(p)<2:
		shade[i]="#0"+p + "0824"
	else:
		shade[i]="#"+p+"824"

makeStyleSheet(size,shade)
makeHomePage(word,size)

x = "l = c("
for i in range(len(top)-1):
	x = x+str(top[i])+","
x = x + str(top[i]) + ");hist(l)"
makeHisto(x)
y = "l=c("
for i in range(14):
	y = y+str(top[i])+","
y = y + str(top[14]) + ");library(lattice);histogram(l)"
makeFreq(y)

os.startfile("homepage.html")
os.remove("test.txt")