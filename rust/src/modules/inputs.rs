#![allow(dead_code)]

use std::io::{stdin, BufRead, stdout};
use std::{io::Write, str::FromStr};
use std::fmt::Display;
use num::{Num, Float};

pub fn input_number() -> i32 {
    let number: i32;
    print!("\nInput number(s): ");
    std::io::stdout().flush().unwrap();
    loop {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).expect("Can't read line");
        match input.trim().parse::<i32>() {
            Ok(n) => { number = n; break; },
            Err(_) => { print!("Please input number(s): "); std::io::stdout().flush().unwrap(); },
        }
    }
    return number;
}

pub fn flip_h_input() -> String {
    let mut input = String::new();
    print!("Input something: ");
    std::io::stdout().flush().unwrap();
    std::io::stdin().read_line(&mut input).expect("Can't read line");
    return input.trim().chars().rev().collect();
}

pub fn input_num<T: Num + Display + FromStr>() -> Result<T, <T as FromStr>::Err> {
    let input = stdin().lock().lines().next().unwrap().unwrap();
    input.trim().parse()
}

pub fn input_num_till_success<T: Num + Display + FromStr>() -> T {
    loop {
        let input = stdin().lock().lines().next().unwrap().unwrap();
        match input.trim().parse::<T>() {
            Ok(n) => return n,
            Err(_) => { print!("Please insert number\n> "); stdout().flush().unwrap(); },
        }
    }
}


