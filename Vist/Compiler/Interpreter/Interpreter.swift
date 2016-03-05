//
//  Interpreter.swift
//  Vist
//
//  Created by Josef Willsher on 04/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


private struct Stack {
    
}


/*

pub struct Queue<T> {
    head: usize,
    tail: usize,
    size: usize,
    count: usize,
    ptr: Unique<T>,
}

impl<T> Queue<T> {
    pub fn new() -> Queue<T> {
        let initial_size = 1_usize;
        let alloc_size = initial_size.checked_mul(mem::size_of::<T>())
                                     .expect("capacity overflow");
        Queue {
            head: 0,
            tail: 0,
            size: initial_size,
            count: 0,
            ptr: unsafe { Unique::new(heap::allocate(alloc_size, mem::align_of::<T>()) as *mut T) },
        }
    }

    pub fn count(&self) -> usize {
        return self.count;
    }

    pub fn push(&mut self, elem: T) {
        if (self.tail % self.size) == (self.head % self.size) && self.count != 0 {
            let alloc_size = (self.size * 2)
                                 .checked_mul(mem::size_of::<T>())
                                 .expect("capacity overflow");
            unsafe {
                let temp = heap::allocate(alloc_size, mem::align_of::<T>()) as *mut T;
                ptr::copy(self.ptr.offset((self.head % self.size) as isize),
                          temp,
                          self.size - (self.head % self.size));
                ptr::copy(self.ptr.offset(0),
                          temp.offset((self.size - (self.head % self.size)) as isize),
                          (self.head % self.size));
                heap::deallocate(*self.ptr as *mut _,
                                 mem::size_of::<T>() * self.size,
                                 mem::align_of::<T>());
                self.ptr = Unique::new(temp);
            }
            self.size *= 2;
            self.head = 0;
            self.tail = self.count;
            unsafe {
                ptr::write(self.ptr.offset(self.tail as isize), elem);
            }
        } else {
            unsafe {
                ptr::write(self.ptr.offset((self.tail % self.size) as isize), elem);
            }
        }
        self.tail += 1;
        self.count += 1;
    }

    pub fn pop(&mut self) -> Option<T> {
        if self.count != 0 {
            let result = Some(unsafe {
                ptr::read_and_drop(self.ptr.offset((self.head % self.size) as isize))
            });
            self.head += 1;
            self.count -= 1;
            result
        } else {
            None
        }
    }
}

impl<T> Drop for Queue<T> {
    fn drop(&mut self) {
        if self.size != 0 {
            unsafe {
                heap::deallocate(*self.ptr as *mut _,
                                 mem::size_of::<T>() * self.size,
                                 mem::align_of::<T>());
            }
        }
    }
}

*/


