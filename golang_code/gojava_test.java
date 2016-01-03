//Client.java
//主要是连接服务端的9000端口，然后读数据，写数据
package pri.guanlaolin.socket;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {

    private PrintWriter cout;
    private Socket socket;

    public Client() throws UnknownHostException, IOException,
            InterruptedException {
        // TODO Auto-generated constructor stub

        this.socket = new Socket("127.0.0.1", 9000);   //连接服务器9000端口

        this.cout = new PrintWriter(socket.getOutputStream());
        this.cout.println("你好,我是客户端！");     //向服务器写入数据

        BufferedReader br = new BufferedReader(new InputStreamReader(
                socket.getInputStream()));

        String line = "连接服务器成功";
        System.out.println(line);

        while (line != null) {
            line = br.readLine();     //读取服务器数据
            System.out.println(line);     
            this.cout.println("客户端收到，客户端收到");     //向服务器发送数据
            this.cout.flush();
            Thread.sleep(1000);    //延时1秒
        }
        br.close();
        this.cout.close();
        socket.close();
    }

    public static void main(String[] args) throws UnknownHostException,
            IOException, InterruptedException {
        // TODO Auto-generated method stub
        new Client();
    }

}
