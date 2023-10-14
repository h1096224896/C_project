import requests
from lxml import etree
from selenium import webdriver

url = 'https://www.baidu.com/'
headers = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.82"
}
res = requests.get(url, headers=headers)
# 转为etree对象
html = etree.HTML(res.text, etree.HTMLParser())
# 获取所有的a标签
a_list = html.xpath('//a')
for a in a_list:
    # 获取a标签的href属性
    href = a.xpath('./@href')
    # 获取a标签的文本
    text = a.xpath('./text()')
    print(href, text)
# 存储到list
for i in range(len(a_list)):
    href = a_list[i].xpath('./@href')
    text = a_list[i].xpath('./text()')
    a_list[i] = [href, text]
print(a_list)