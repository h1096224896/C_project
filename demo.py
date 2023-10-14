import requests
from lxml import etree

url = 'http://www.baidu.com'
response = requests.get(url)
html = etree.HTML(response.text)
result = etree.tostring(html)
print(result.decode('utf-8'))
