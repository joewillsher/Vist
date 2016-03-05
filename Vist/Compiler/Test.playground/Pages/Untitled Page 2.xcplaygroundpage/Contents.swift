//: [Previous](@previous)

extension UnsafeMutablePointer {
    mutating func advanceByAlignOf<T>(el: T.Type) { self = advancedBy(alignof(el)) }
    mutating func recedeByAlignOf<T>(el: T.Type) { self = advancedBy(-alignof(el)) }
}

struct Stack {
    var stack, stackPtr, basePtr: UnsafeMutablePointer<Int8>
    /// The maximum size of stack allocated
    var capacity: Int = 10
    /// The offset of the stack pointer
    var offset: Int { return stack.distanceTo(stackPtr) }
    
    init() {
        stack = UnsafeMutablePointer<Int8>.alloc(capacity)
        stackPtr = stack
        basePtr = stackPtr
    }
    
    /// Pushes an element onto the stack
    mutating func push<T>(element: T) {
        stackPtr.advanceByAlignOf(T)
        let ptr = unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self)
        ptr.initialize(element)
    }
    
    /// Pops an element of type `type` and moves the stack
    /// pointer backwards
    mutating func pop<T>(type: T.Type) -> T {
        let ptr = unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self)
        stackPtr.recedeByAlignOf(T)
        return ptr.memory
    }
    
    /// Reads the current stack pointer as `type`
    func read<T>(type: T.Type) -> T {
        return unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).memory
    }

    /// Adds a new stack frame
    func call() {
        
    }
    
}

// tests

var s = Stack()

s.stackPtr // 0x7FBA43520A10

s.push(1)
s.push(Int32(2))
s.push(false)

// stack: 00000001 , 0001 , 0

s.stackPtr // 0x7FBA43520A1D
s.read(Bool) // false
s.pop(Bool) // false

// stack: 00000001 , 0002

s.stackPtr // 0x7FBA43520A1C
s.read(Int32) // 2
s.pop(Int32) // 2

// stack: 00000001

s.stackPtr // 0x7FBA43520A18
s.read(Int) // 1
s.pop(Int) // 1




//: [Next](@next)
