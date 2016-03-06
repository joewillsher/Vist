//: [Previous](@previous)

extension UnsafeMutablePointer {
    mutating func advanceByAlignOf<T>(el: T.Type) { self = advancedBy(alignof(el)) }
    mutating func recedeByAlignOf<T>(el: T.Type) { self = advancedBy(-alignof(el)) }
}

final class Stack {
    var stack, stackPtr, basePtr: UnsafeMutablePointer<Int8>
    /// The maximum size of stack allocated
    var capacity: Int
    var bytesOccupied: Int { return offset }
    
    /// The offset of the stack pointer
    var offset: Int { return stack.distanceTo(stackPtr) }
    /// The offset of the base pointer
    var baseOffset: Int { return stack.distanceTo(basePtr) }
    
    init() {
        capacity = 100
        stack = UnsafeMutablePointer<Int8>.alloc(capacity)
        stackPtr = stack
        basePtr = stackPtr
    }
    
    /// Moves the stack into a new buffer twice the old size
    private func initialiseNewBuffer() {
        let oldCapacity = capacity
        capacity *= 2
        // create new buffer & copy into it
        let newStack = UnsafeMutablePointer<Int8>.alloc(capacity)
        newStack.moveInitializeFrom(stack, count: oldCapacity)
        // move sp & bp into this
        stackPtr = newStack.advancedBy(offset)
        basePtr = newStack.advancedBy(baseOffset)
        // remove refs to old stack buffer
        stack.destroy(oldCapacity)
        stack = newStack
    }
    
    deinit {
        stack.destroy(capacity)
    }
    
    /// Pushes an element onto the stack
    func push<T>(element: T) {
        if bytesOccupied + alignof(T) > capacity { initialiseNewBuffer() }
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).initialize(element)
        stackPtr.advanceByAlignOf(T)
    }
    private func pushUninitialised<T>(ty: T) {
        if bytesOccupied + alignof(T) > capacity { initialiseNewBuffer() }
        stackPtr.advanceByAlignOf(T)
    }
    private func initialise<T>(val: T) {
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).predecessor().initialize(val)
    }
    
    /// Pops an element of type `type` and moves the stack
    /// pointer backwards
    func pop<T>(type: T.Type) -> T {
        let val = read(T)
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).destroy()
        stackPtr.recedeByAlignOf(T)
        return val
    }
    
    func trim<T>(type: T.Type) {
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).destroy()
        stackPtr.recedeByAlignOf(T)
    }
    
    /// Reads the current stack pointer as `type`
    func read<T>(type: T.Type) -> T {
        return unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).predecessor().memory
    }
    
    /// Adds a new stack frame
    func call<Ret, Params>(returns ret: Ret.Type, params: Params) {
        pushUninitialised(Ret) // allocate return mem
        let s = offset
        push(params) // push params
        push(s) // push return offset
        push(baseOffset) // push old base ptr
        basePtr = stackPtr // this is the start of a new stack frame
    }
    
    func ret<Ret>(val: Ret) {
        let head = offset // current size of the stack
        stackPtr = basePtr // move to beginning og stack frame
        basePtr = stack.advancedBy(pop(Int)) // pop off the old base ptr
        let s = stack.advancedBy(pop(Int)) // pop off return offset
        s.stride(to: stack.advancedBy(head), by: 1).map { $0.destroy() } // remove all of this stack frame
        stackPtr = s // move to return mem
        initialise(val)
    }

    var description: String {
        let stackDesc = stack.stride(to: stackPtr, by: 1)
            .map { String($0.memory) }
            .joinWithSeparator("")
        let o = Array(count: offset-1, repeatedValue: " ")
            .joinWithSeparator("")
        return "\(stackDesc)\n\(o)^\(stackPtr)"
    }
}

// tests

let s = Stack()
let count = 100

// a function takes 12 as param
// and returns an int
s.call(returns: Int.self, params: 12)
// we do stuff in function
s.push(1)
s.push(2)
// we return from function
s.ret(111)
s.pop(Int) // validate return value is there



for a in 0..<count {
    s.push(a)
    s.read(Int)
}

for a in 0..<count {
    s.pop(Int)
}



//: [Next](@next)
