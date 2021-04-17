using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppCsharp
{
    class DoublyLinkedList<T>
    {
        private T data;
        private DoublyLinkedList<T> next;
        private DoublyLinkedList<T> prev;

        public DoublyLinkedList()
        {
            data = default(T);
            next = null;
            prev = null;
        }

        public DoublyLinkedList(T data)
        {
            this.data = data;
            next = null;
            prev = null;
        }

        public DoublyLinkedList<T> InsertNext(T data)
        {
            DoublyLinkedList<T> node = new DoublyLinkedList<T>(data);

            if (this.next == null)
            {
                node.prev = this;
                node.next = null;
                this.next = node;
            }
            else
            {
                // Insert in the middle
                DoublyLinkedList<T> temp = this.next;
                node.prev = this;
                node.next = temp;
                this.next = node;
                temp.prev = node;
            }
            return node;
        }

        public DoublyLinkedList<T> InsertPrev(T data)
        {
            DoublyLinkedList<T> node = new DoublyLinkedList<T>(data);

            if (this.prev == null)
            {
                node.prev = null;
                node.next = this;
                this.prev = node;
            }
            else
            {
                // Insert in the middle
                DoublyLinkedList<T> temp = this.prev;
                node.prev = temp;
                node.next = this;
                this.prev = node;
                temp.next = node;
            }
            return node;
        }

        public void TraverseFront()
        {
            TraverseFront(this);
        }

        public void TraverseFront(DoublyLinkedList<T> node)
        {
            if (node == null)
                node = this;

            Console.WriteLine("\n\nTraversing in Forward Direction\n\n");

            while (node != null)
            {
                Console.WriteLine(node.data);
                node = node.next;
            }
        }

        public void TraverseBack()
        {
            TraverseBack(this);
        }

        public void TraverseBack(DoublyLinkedList<T> node)
        {
            if (node == null)
                node = this;

            Console.WriteLine("\n\nTraversing in Backward Direction\n\n");

            while (node != null)
            {
                Console.WriteLine(node.data);
                node = node.prev;
            }
        }
    }
}
