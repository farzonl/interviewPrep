using System;
using System.Collections.Generic;

namespace datastructures
{
    public interface IPoint {
        int x {get; set;}
        int y {get; set;}
    }

    public interface IBoundary {
        bool contains(IPoint p);
    }

    public class Rectangle : IBoundary {
        public int x {get; private set;}
        public int y {get; private set;}
        public int w {get; private set;}
        public int h {get; private set;}
        public Rectangle(int x, int y, int w, int h) {
            this.x = x;
            this.y = y;
            this.w = w;
            this.h = h;
        }

        // center +- width and height
        public bool contains(IPoint p) {
            return p.x > (this.x - this.w ) &&
                   p.x < (this.x + this.w)  &&
                   p.y > (this.y - this.h)  &&
                   p.y < (this.y + this.h);
        }
    }

    public class Particle : IPoint {
        public int x {get; set;}
        public int y {get; set;}
        public Particle(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public class QuadTree {
        public int capacity {get; private set;}
        public QuadTree NW,NE,SW,SE;
        public List<IPoint> points {get; private set;}
        public Rectangle boundary {get; private set;}
        public bool isSubdivided {get; private set;}

        public QuadTree(Rectangle boundary, int capacity=10) {
            this.capacity = capacity;
            this.boundary = boundary;
            isSubdivided = false;
            points = new List<IPoint>();
        }

        public bool insert(IPoint p) {
            if(!this.boundary.contains(p)) {
                return false;
            }
            if(points.Count < capacity) {
                points.Add(p);
                return true;
            } 
            if(!isSubdivided) {
                subdivide();
            }
            if(NW.insert(p)) {
                Console.WriteLine("North west add");
                return true;
            } else if(NE.insert(p)) {
                Console.WriteLine("North east add");
                return true;
            } else if (SW.insert(p)) {
                Console.WriteLine("South west add");
                return true;
            } else if (SE.insert(p)) {
                Console.WriteLine("South east add");
                return true;
            }
            return false;
        }

        //  _________
        // | NW | NE |
        // |____|____|
        // | SW | SE |
        // |____|____|
        public void subdivide() {
            int x = this.boundary.x;
            int y = this.boundary.y;
            int w = this.boundary.w;
            int h = this.boundary.h;
            Rectangle neR = new Rectangle(x + w / 2, y - h/2, w / 2, h / 2 );
            Rectangle nwR = new Rectangle(x - w / 2, y - h/2, w / 2, h / 2 );
            Rectangle seR = new Rectangle(x + w / 2, y + h/2, w / 2, h / 2 );
            Rectangle swR = new Rectangle(x - w / 2, y + h/2, w / 2, h / 2 );
            NW = new QuadTree(nwR, this.capacity);
            NE = new QuadTree(neR, this.capacity);
            SW = new QuadTree(swR, this.capacity);
            SE = new QuadTree(seR, this.capacity);
            isSubdivided = true;
        }
    }
}