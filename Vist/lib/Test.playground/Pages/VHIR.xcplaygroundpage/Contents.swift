

func scope() {
    
    let a: Int
    
    defer {
        print(a)
    }
    
    a = 1
}

