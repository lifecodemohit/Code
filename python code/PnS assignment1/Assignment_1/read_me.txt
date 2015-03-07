The Main script is written in Python 2.7 in file Q7.py
Run the script and enter the count for the site according to the data required.
Before runnning this file Python lib BeautifulSoup and Unidecode is necessary.
	To install the lib:
		1.Extract "beautifulsoup4-4.3.2.tar.gz"
		2.Using powershell(windows) or terminal(linux) go inside the folder beautifulsoup4-4.
		3.run command: "python setup.py install"
		4.Similarly install the library Unidecode
Once the libraries are installed the python program is ready to run. 
It will create a text file namely "text.txt" which will be delted on it's own once the program is terminated.
For word cloud the program will write a source code for webpage and create a html and css file. The webpage will run on it's own in a browser. If it doesn't please run the "homepage.html" in any browser.
File for Histogram of top 20 most repeating words is created by the script and is created with the name of "histo.r" and will run in the R compiler.
Similarly for frequence polygon for top 15 words, freq.r is created in the same folder, which will show the required frequency histogram in R
Assumptions:
All the text present on the web page is collected to generate the data, after the reading the comment of one of the TAs made it clear "https://www.usebackpack.com/discussions/6778"
Word cloud is made only from the 20 most repeating words present in the webpage content.