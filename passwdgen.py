# python script reads online
import requests
import sys

#requesthtml basically returns a string with what it reads about the html page
#headers needs a rework
def requesthtml(link):
    headers = {"User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:90.0) Gecko/20100101 Firefox/90.0"}
    content = requests.get(link,headers=headers).content
    return content

def main(req):
    if(req==1):
        sample = input()
        print(requesthtml(sample))

if __name__ == "__main__": 
    print("\033[1;36;1m"+open("other/intro.txt").read());
    
    