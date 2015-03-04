import string
import urllib
import re
link = "http://dblp.org/search/api/?q=ce:author:anil_k_jain:*&h=1000&c=4&f=0&format=xml"
b = urllib.urlretrieve(link, "test.txt")
f = open("test.txt", "r")
words=[]
content=[]
rmwords=[]
for line in f:
		regex = ur"\<author\>(.+?)\</author\>+?"
		rmwords.append(re.findall(regex, line))
		words.append(re.findall("\>(.*?)\<", line))
for word in words:
	for i in word:
		content.append(i)
content = [s.translate(None, string.punctuation) for s in content]

content2 = []
for i in content:
	if i!='':
		content2.append(i)
f.close()

rmwords2=[]
for i in rmwords:
	for j in i:
		k = j.split(" ")
		for l in k:
			rmwords2.append(l)
rmwords2 = set(rmwords2)
rmwords2 = list(rmwords2)
f = open("print.txt","w")
for i in content2:
	j = i.split(" ")
	for k in j:
		if k not in rmwords2:
			print >> f, k
f.close()

def makeStyleSheet(size):
	file=open("myCs325Style.css", "wt")
	file.write("""body {background-color: #000}
	
	h20  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[0] +"""; align="justify"
	}
	h21  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[1] +""";
	}
	h22  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[2] +""";
	}
	h23  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[3]+""";
	}
	h24  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[4]+""";
	}
	h25  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[5]+""";
	}
	h18  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[18]+""";
	}
	h7  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[7]+""";
	}
	h26  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[6]+""";
	}
	h8  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[8]+""";
	}
	h9  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[9]+""";
	}
	h10  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[10]+""";
	}
	h11 { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[11]+""";
	}
	h12  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[12]+""";
	}
	h13  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[13]+""";
	}
	h14  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[14]+""";
	}
	h15  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[15]+""";
	}
	h16  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[16]+""";
	}
	h17  { color: #0000FF;
	 font-family:"Times New Roman", Times, serif;
	 font-size: """+size[17]+""";
	}
	h19  { color: #0000FF;
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
	<link rel="stylesheet" href="myCs325Style.css" type="text/css"/>
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
fp=open("print.txt", "r")
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
top = []
j = 1
final = ({})
for i in range(n-20,n):
	top.append(freq[i])
for k,v in a.items():
	if v in top: 
		final[k] = v
		print k, v
		j+=1
fp.close()	
	
word = []
size = []
for k,v in final.items():
	size.append(v)
	word.append(k)
for i in range(len(size)):
	size[i] = size[i]/5	
	size[i] = str(size[i])	
	size[i] += "px"	
makeStyleSheet(size)
makeHomePage(word,size)
