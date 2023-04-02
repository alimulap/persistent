#![allow(dead_code)]

use std::io::Write;

use crate::modules::inputs::*;
use crate::modules::searchs::*;

pub fn test_sequential_search() {
    let n = rand::random::<i32>().abs() % 100 + 1;
    let mut vect = Vec::with_capacity(n as usize);
    for _ in 0..n {
        vect.push(rand::random::<i32>() % 100);
    }
    println!("{:?}", vect);

    print!("Number you want to search: ");
    std::io::stdout().flush().unwrap();
    let input = input_num_till_success();

    let idxs = sequential_search(vect, input);

    if idxs.len() > 0 {
        println!("It's on index(s): ");
        println!("{:?}", idxs);
    } else {
        println!("Found none.");
    }
}
