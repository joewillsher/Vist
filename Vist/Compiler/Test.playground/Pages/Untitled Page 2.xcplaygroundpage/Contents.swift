//: [Previous](@previous)

extension UnsafeMutablePointer {
    mutating func advanceByAlignOf<T>(el: T.Type) { self = advancedBy(alignof(el)) }
    mutating func recedeByAlignOf<T>(el: T.Type) { self = advancedBy(-alignof(el)) }
}

final class Stack {
    var stack, stackPtr, basePtr: UnsafeMutablePointer<Int8>
    /// The maximum size of stack allocated
    var capacity: Int
    var bitsOccupied: Int { return offset/8 }
    
    /// The offset of the stack pointer
    var offset: Int { return stack.distanceTo(stackPtr) }
    /// The offset of the base pointer
    var frameOffset: Int { return stack.distanceTo(basePtr) }
    
    init() {
        capacity = 1
        stack = UnsafeMutablePointer<Int8>.alloc(capacity)
        stackPtr = stack
        basePtr = stackPtr
    }
    
    /// Moves the stack into a new buffer twice the old size
    private func initialiseNewBuffer() {
        let oldCapacity = capacity
        capacity *= 2
        let newStack = UnsafeMutablePointer<Int8>.alloc(capacity)
        newStack.moveInitializeFrom(stack, count: oldCapacity)
        stackPtr = stack.advancedBy(offset)
        basePtr = stack.advancedBy(frameOffset)
        stack = newStack
    }
    
    deinit {
        stack.dealloc(capacity)
    }
    
    /// Pushes an element onto the stack
    func push<T>(element: T) {
        if bitsOccupied >= capacity { initialiseNewBuffer() }
        let ptr = unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self)
        ptr.initialize(element)
        stackPtr.advanceByAlignOf(T)
    }
    
    /// Pops an element of type `type` and moves the stack
    /// pointer backwards
    func pop<T>(type: T.Type) -> T {
        let val = read(T)
        stackPtr.recedeByAlignOf(T)
        return val
    }
    
    /// Reads the current stack pointer as `type`
    func read<T>(type: T.Type) -> T {
        return unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).predecessor().memory
    }

    /// Adds a new stack frame
    func call() {
        
    }

    var description: String {
        let stackDesc = stack.stride(to: stackPtr, by: 1)
            .map({ String($0.memory) })
            .joinWithSeparator("")
        let o = Array(count: offset-1, repeatedValue: " ")
            .joinWithSeparator("")
        return "\(stackDesc)\n\(o)^\(stackPtr)"
    }
}

// tests

let s = Stack()

for a in 0..<10 {
    s.push(a)
}

for a in 0..<10 {
    s.pop(Int)
}



//: [Next](@next)
