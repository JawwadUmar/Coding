
class Queue:
    def __init__(self, mxSize):
        self.mxSize = mxSize
        self.q = [0]*mxSize
        self.first = -1
        self.last = -1
    
    def isEmpty(self):
        if self.first == -1:
            return True
        
        return False
    
    def enqueue(self, x):

        if (self.last + 1)%(self.mxSize) == self.first:
            raise Exception("Queue is already full")
        
        if self.isEmpty():
            self.first = 0
        
        
        self.last = (self.last + 1)%(self.mxSize)
        self.q[self.last] = x
    
    def dequeue(self):

        if(self.first == self.last):
            ##queue will become empty
            self.first = -1
            self.last = -1

        if(self.isEmpty() ==False):
            self.first = (self.first + 1)%(self.mxSize)

    def front(self):
        if self.isEmpty():
            raise Exception("The queue is empty")
        return self.q[self.first]




que = Queue(5)

que.enqueue(5)
que.enqueue(2)
que.enqueue(3)
que.enqueue(7)
que.enqueue(6)


que.dequeue()
que.dequeue()
que.dequeue()
que.dequeue()



print(que.front())





    

    
    
