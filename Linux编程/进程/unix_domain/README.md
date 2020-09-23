unix domain 是一种域套接字（本地套接字）  
用于同一台机器上的进程间通信  
采用的是类似tcp/udp的通信方式  

unix domain 在同一台机器上的数据传输速度比tcp/udp要快很多  
  
unix domain什么时候用最合适  
同一台机器上 多个进程会频繁向另外一个进程发送数据的时候  
