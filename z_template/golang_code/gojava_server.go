//server.go
//客户端，主要是在9000端口创建监听程序，用于接受客户端连接
package main

import (
    "bufio"
    "fmt"
    "log"
    "net"
    "time"
)

func main() {
    tcpAddr, err := net.ResolveTCPAddr("tcp", "127.0.0.1:9000")
    if err != nil {
        log.Fatalln("地址解析错误", err)
    }
    tcpListener, err := net.ListenTCP("tcp", tcpAddr)    //创建监听
    if err != nil {
        log.Fatalln("地址监听失败", err)
    }

    defer tcpListener.Close()

    fmt.Println("开始接受客户端连接：")
    tcpConn, err := tcpListener.AcceptTCP()    //接受客户端连接
    if err != nil {
        log.Fatalln("接受客户端连接失败", err)
    }
    fmt.Println("客户端连接成功")
    _, err = tcpConn.Write([]byte("你好，我是服务器，欢迎连接！\n"))    //向客户端写数据
    if err != nil {
        log.Fatalln("往客户端数据失败", err)
    }
    reader := bufio.NewReader(tcpConn)

    for {
        line, err := reader.ReadString('\n')   //读取客户端发来的数据
        if err != nil {
            log.Fatalln("读取数据失败", err)
        }
        fmt.Println("客户端发来数据：", line)

        _, err = tcpConn.Write([]byte("我是服务器，我是服务器，收到请回答，收到请回答\n"))
        if err != nil {
            log.Fatalln("往客户端发送数据失败", err)
        }
        time.Sleep(1 * time.Second)    //延时一秒
    }
}
