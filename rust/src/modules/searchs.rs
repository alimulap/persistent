pub fn sequential_search(arr: Vec<i32>, keyword: i32) -> Vec<i32> {
    let mut res: Vec<i32> = Vec::new();
    arr.iter().enumerate().for_each(|(i,v)| {
        if *v == keyword {
            res.push(i as i32);
        }
    });
    return res;
}
