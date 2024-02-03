# XilouReader<br />
专注pdf阅读，pdf处理，ofd阅读，ofd处理,pdf转ofd以及ofd转pdf引擎功能开发。基于pdfium的ofd/pdf双引擎版式阅读器。<br />
<br />
<br />
现状<br />
1。PDF阅读<br />
2。OFD常规文档，发票，公文的阅读及签章验证通常不会有问题，有问题请报issue附上文档<br />
<br />
history:<br />
2023-12-25:实现PDF转.txt文件功能<br />
2024-02-03：简单pdf转ofd<br />
<br />
目录说明：<br />
out/release目录下是windows下的预编译版本，只测试了windows11(windows10应该也可以)<br />
ofdcases目录用于上传ofd用例文档， 有任何渲染有问题的文档，欢迎 pull request<br />
convertcases目录用于上传pfd转ofd, ofd转pdf用例文档， 有任何有问题文档，欢迎 pull request<br />
TODO<br />
1. 签章解析（ofd已支持签章解析及验章）<br />
2. 字体裁剪<br />
3。 pdf转ofd<br />
<br />
preview:<br />
![image](preview/drawparam.jpg)
![image](preview/ticket.png)
![image](preview/clips.jpg)
![image](preview/6F575221-72B1-4e0f-8EA1-5457D8205C03.png)
![image](preview/signed.png)
![image](preview/verify.png)
![image](preview/img_border.png)
![image](preview/annots.png)
convert:
![image](preview/pdf2ofd.png)

