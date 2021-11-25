
# Queue

There are two variables i.e. front and rear, that are implemented in the case of every queue. Front and rear variables point to the position from where insertions and deletions are performed in a queue. Initially, the value of front and queue is -1 which represents an empty queue. Array representation of a queue containing 5 elements along with the respective values of front and rear, is shown in the following figure.


![Singly Linked List](https://github.com/saielnaik/Data-Structure-in-C/blob/main/Queue/array-representation-of-queue.png)

The above figure shows the queue of characters forming the English word "HELLO". Since, No deletion is performed in the queue till now, therefore the value of front remains -1 . However, the value of rear increases by one every time an insertion is performed in the queue. After inserting an element into the queue shown in the above figure, the queue will look something like following. The value of rear will become 5 while the value of front remains same.

![Singly Linked List](https://github.com/saielnaik/Data-Structure-in-C/blob/main/Queue/array-representation-of-queue2.png)

After deleting an element, the value of front will increase from -1 to 0. however, the queue will look something like following.

![Singly Linked List](https://github.com/saielnaik/Data-Structure-in-C/blob/main/Queue/array-representation-of-queue3.png)
