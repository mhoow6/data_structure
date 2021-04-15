using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppCsharp
{
    public class LinkedQueue<T>
    {
        private class Node
        {
            public Node(Node link, T data)
            {
                Link = link;
                Data = data;
            }

            // internal: 같은 프로젝트(어셈블리) 내에서만 접근이 가능
            public Node Link { get; internal set; }
            public T Data { get; }
        }

        private Node front;
        private Node rear;

        public void Enqueue(T item)
        {
            Node node = new Node(null, item);

            if (rear == null)
            {
                front = node;
                rear = node;
            } 
            else
            {
                rear.Link = node;
                rear = node;
            }
        }

        public bool TryPeek(out T item)
        {
            if (front == null)
            {
                // default: 자료형의 기본값으로 초기화
                item = default(T);
                return false;
            }

            item = front.Data;

            return true;
        }

        public T peek()
        {
            if (front == null)
                throw new InvalidOperationException("Queue is empty.");

            return front.Data;
        }

        public bool TryDequeue(out T item)
        {
            if (front == null)
            {
                item = default(T);

                return false;
            }

            item = front.Data;
            front = front.Link;

            return true;
        }

        public T Dequeue()
        {
            if (front == null)
                throw new InvalidOperationException("Queue is empty.");

            T item = front.Data;
            front = front.Link;

            return item;
        }

        public void Printqueue()
        {
            Console.Write("< Queue: ");
            while (front.Link != null)
            {
                Console.Write(front.Data + " ");
                front = front.Link;
            }
            Console.Write(front.Data);
            Console.WriteLine(">");
        }
    }
}

/* Code Referenece 
 * https://stackoverflow.com/questions/59496346/queue-implementation-using-linked-list-c-sharp
 */
