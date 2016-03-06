//
//  Interpreter.swift
//  Vist
//
//  Created by Josef Willsher on 04/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

// Test document -- implementation of a virtual machine
// stack for use in a VHIR interpreter

private extension UnsafeMutablePointer {
    mutating func advanceByAlignOf<T>(el: T.Type) { self = advancedBy(alignof(el)) }
    mutating func recedeByAlignOf<T>(el: T.Type) { self = advancedBy(-alignof(el)) }
}

final class Stack {
    private var stack, stackPtr, basePtr: UnsafeMutablePointer<Int8>
    /// The maximum size of stack allocated
    private var capacity: Int
    private var bytesOccupied: Int { return offset }
    
    /// The offset of the stack pointer
    private var offset: Int { return stack.distanceTo(stackPtr) }
    /// The offset of the base pointer
    private var baseOffset: Int { return stack.distanceTo(basePtr) }
    
    init() {
        capacity = 100
        stack = UnsafeMutablePointer<Int8>.alloc(capacity)
        stackPtr = stack
        basePtr = stackPtr
    }
    
    deinit {
        stack.destroy(capacity)
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
    
    /// Pushes an element onto the stack
    func push<T>(element: T) {
        if bytesOccupied + alignof(T) > capacity { initialiseNewBuffer() }
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).initialize(element)
        stackPtr.advanceByAlignOf(T)
    }
    /// Pops an element of type `type` and moves the stack
    /// pointer backwards
    func pop<T>(type: T.Type) -> T {
        let val = read(T)
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).destroy()
        stackPtr.recedeByAlignOf(T)
        return val
    }
    
    /// Reads the current stack pointer as `type`
    func read<T>(type: T.Type, advance: Int = 0) -> T {
        return unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).predecessor().advancedBy(advance).memory
    }
    
    /// Adds a new stack frame and creates a function
    func call<Ret, Params>(returns ret: Ret, params: Params) {
        pushUninitialised(Ret) // allocate return mem
        push(baseOffset) // push old base ptr
        basePtr = stackPtr // this is the start of a new stack frame
        push(params) // push params
    }
    
    /// Returns from the current function
    func ret<Ret>(val: Ret) {
        s.destroyFrame() // destroy stack frame, moves to
        basePtr = stack.advancedBy(pop(Int)) // pop off the old base ptr
        initialise(val) // flls the mem for the return value
    }
    
    /// Pushes uninitialised memory of type `ty` onto the stack
    private func pushUninitialised<T>(type: T) {
        if bytesOccupied + alignof(T) > capacity { initialiseNewBuffer() }
        stackPtr.advanceByAlignOf(T)
    }
    /// Intiialises the current stack pointer with `val`
    private func initialise<T>(val: T) {
        unsafeBitCast(stackPtr, UnsafeMutablePointer<T>.self).predecessor().initialize(val)
    }
    /// Destroys the contents of the current frame and moves
    /// the stack pointer back to the base pointer
    private func destroyFrame() {
        let s = basePtr.successor()
        s.destroy(s.distanceTo(stackPtr)) // remove all of this stack frame
        stackPtr = basePtr // move to return mem
    }
    
    
    
    var description: String {
        return stack.stride(to: stackPtr, by: 1)
            .map { String($0.memory) }
            .joinWithSeparator("")
    }
}

