using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppCsharp
{
    class LinkedStack<T>
    {
        private T data;
        private LinkedStack<T> link;

        public LinkedStack()
        {
            this.data = default(T);
            this.link = null;
        }

        public LinkedStack(T data)
        {
            this.data = data;
            this.link = null;
        }

        public void push(T data)
        {
            LinkedStack<T> node = new LinkedStack<T>(data);

            if (this.link == null)
                this.link = node;
            else
            {
                LinkedStack<T> temp = this;
                while (temp.link != null)
                    temp = temp.link;
                temp.link = node;
            }
        }

        public void pop()
        {
            if (this.link == null)
            {
                Console.WriteLine("Sorry. You can't empty the stack.");
                return;
            }
                
            if (this.link.link == null)
            {
                this.link = null;
                return;
            }

            LinkedStack<T> temp = this.link;
            while (temp.link.link != null)
                temp = temp.link;
            temp.link = null;
        }

        public void print()
        {
            LinkedStack<T> _this = this;
            Console.Write("Stack: < ");
            while (_this != null)
            {
                Console.Write(_this.data + " ");
                _this = _this.link;
            }
            Console.WriteLine(">");
        }
    }
}
