from threading import Thread, currentThread, activeCount
from time import sleep 

def testTest(s):
    print "ident:", currentThread().ident
    print "count:", activeCount()
    print s

class MyThread(Thread):
    def __init__(self, name, *args):
	super(MyThread, self).__init__(name = name)
	self.data = args 

    def run(self):
	print self.name, self.data

def test():
    print "__thread_start__"
    sleep(10)
    print "__thread_exit__"

def run():
    t = Thread(target = test) 
    t.start()
    t.join(2)

    print t.isAlive()
    t.join()

    print "over!"



Thread( target = testTest, args = ("Hello",)).start() 
MyThread("abc", range(10)).start() 
run() 



