//use twitter_v2::authorization::BearerToken;
//use twitter_v2::query::TweetField;
//use twitter_v2::TwitterApi;
//
//#[tokio::main]
//async fn main() {
//    let auth = BearerToken::new("AAAAAAAAAAAAAAAAAAAAAKgKpQEAAAAAEX5kbFGgH8Fjk4UYmevhCBRSXVg%3DnB0hT0AeuRIYmVQuBu4CiIRWjUA2wKNVWAl6LoLc1tdXjUBP0J");
//    let tweet = TwitterApi::new(auth)
//        .get_tweet(1261326399320715264)
//        .tweet_fields([TweetField::AuthorId, TweetField::CreatedAt])
//        .send().await.unwrap()
//        .into_data()
//        .expect("this tweet should exist");
//    dbg!(tweet);
//}
fn main() {}

#[cfg(test)]
mod tests {
    use std::{cell::RefCell, cmp::Ordering, rc::Rc};

    use num::integer::Roots;

    fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();
        for i in 0..numbers.len() {
            for j in i + 1..numbers.len() {
                if numbers[i] + numbers[j] == target {
                    result.push(i as i32);
                    result.push(j as i32);
                    return result;
                }
            }
        }
        return result;
    }

    #[test]
    fn test_two_sum() {
        let numbers = vec![2, 7, 11, 15];
        let target = 9;
        let result = two_sum(numbers, target);
        assert_eq!(result, vec![0, 1]);
    }

    fn ikan(mut column_number: i32) -> String {
        let mut result = Vec::new();
        loop {
            //column_number -= 1;
            let a = match column_number % 26 {
                0 => {
                    column_number -= 1;
                    26
                }
                modulus => modulus,
            };
            result.push(a as u8 + 64);
            let b = column_number / 26;
            if b > 0 {
                column_number = b
            } else {
                break;
            }
        }
        result.reverse();
        String::from_utf8(result).unwrap()
    }

    #[test]
    fn test_ikan() {
        assert_eq!(ikan(701), "ZY".to_string())
    }

    fn factorial(n: u128) -> u128 {
        if n == 0 {
            1
        } else {
            n * factorial(n - 1)
        }
    }

    #[test]
    fn test_factorial() {
        for i in 20..200 {
            println!("{}: {}", i, factorial(i));
        }
    }

    fn trailing_zeros(n: i32) -> i32 {
        n / 5 / 5 + n / 5 + n / 25 + n / 125 + n / 625 + n / 3125
    }

    #[test]
    fn test_trailing_zeros() {
        for i in 0..100 {
            println!("{}: {}", i, trailing_zeros(i));
        }
    }

    // Definition for a binary tree node.
    #[derive(Debug, PartialEq, Eq)]
    pub struct TreeNode {
        pub val: i32,
        pub left: Option<Rc<RefCell<TreeNode>>>,
        pub right: Option<Rc<RefCell<TreeNode>>>,
    }
    //
    impl TreeNode {
        #[inline]
        pub fn new(val: i32) -> Self {
            TreeNode {
                val,
                left: None,
                right: None,
            }
        }
    }

    struct BSTIterator {
        root: Option<Rc<RefCell<TreeNode>>>,
        current: Option<Rc<RefCell<TreeNode>>>,
    }

    /**
     * `&self` means the method takes an immutable reference.
     * If you need a mutable reference, change it to `&mut self` instead.
     */
    impl BSTIterator {
        fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
            BSTIterator {
                root: root.clone(),
                current: None,
            }
        }

        fn get_smallest(root: Rc<RefCell<TreeNode>>) -> Rc<RefCell<TreeNode>> {
            let mut current = root;
            loop {
                let temp = match &current.borrow().left {
                    Some(left) => left.clone(),
                    None => break,
                };
                current = temp;
            }
            current
            //while let Some(left) = current.clone().borrow().left {
            //    current = left.clone();
            //}
        }

        fn get_biggest(root: Rc<RefCell<TreeNode>>) -> Rc<RefCell<TreeNode>> {
            let mut current = root;
            loop {
                let temp = match &current.borrow().right {
                    Some(right) => right.clone(),
                    None => break,
                };
                current = temp;
            }
            current
            //while let Some(right) = &current.clone().borrow().right {
            //    current = right.clone();
            //}
        }

        fn real_next(&mut self) -> Option<Rc<RefCell<TreeNode>>> {
            if let Some(current_node) = &self.current {
                let current_val = current_node.borrow().val;
                let mut maybe_current_parent = self.root.clone().unwrap();
                loop {
                    let parent_val = maybe_current_parent.borrow().val;
                    maybe_current_parent = match current_val.cmp(&parent_val) {
                        Ordering::Less => {
                            let left = maybe_current_parent.borrow().left.clone().unwrap();
                            let left_val = left.borrow().val;
                            if left_val == current_val {
                                if let Some(right) = &left.borrow().right {
                                    return Some(Self::get_smallest(right.clone()));
                                } else {
                                    return Some(maybe_current_parent);
                                }
                            } else if current_val > left_val {
                                if current_val == Self::get_biggest(left.clone()).borrow().val {
                                    return Some(maybe_current_parent.clone());
                                } else {
                                    left.borrow().right.clone().unwrap()
                                }
                            } else {
                                left
                            }
                        }
                        Ordering::Greater => maybe_current_parent.borrow().right.clone().unwrap(),
                        Ordering::Equal => {
                            if let Some(right) = &maybe_current_parent.borrow().right {
                                return Some(Self::get_smallest(right.clone()));
                            } else {
                                return None;
                            }
                        }
                    }
                }
            } else {
                Some(Self::get_smallest(self.root.clone().unwrap()))
            }
        }

        fn next(&mut self) -> i32 {
            if let Some(next) = self.real_next() {
                let val = next.borrow().val;
                self.current = Some(next);
                val
            } else {
                0
            }
        }
        //
        fn has_next(&mut self) -> bool {
            self.real_next().is_some()
        }
    }

    #[derive(PartialEq, Debug)]
    struct Position {
        pub x: usize,
        pub y: usize,
    }

    struct Entity {
        pub health: i32,
        pub pos: Position,
        pub lowest_health: i32,
    }

    impl Entity {
        pub fn move_to(&mut self, point: &Position, dungeon: &Vec<Vec<i32>>) {
            loop {
                println!("current: {}", self.health);

                let to_right_value = if self.pos.x == point.x {
                    None
                } else {
                    dungeon.get(self.pos.y).and_then(|y| y.get(self.pos.x + 1))
                };
                let to_down_value = if self.pos.y == point.y {
                    None
                } else {
                    dungeon.get(self.pos.y + 1).and_then(|y| y.get(self.pos.x))
                };

                match (to_right_value, to_down_value) {
                    (Some(value_right), Some(value_down)) => {
                        if value_right > value_down {
                            self.health += value_right;
                            self.pos.x += 1;
                        } else {
                            self.health += value_down;
                            self.pos.y += 1;
                        }
                    }
                    (Some(value), None) => {
                        self.health += value;
                        self.pos.x += 1;
                    }
                    (None, Some(value)) => {
                        self.health += value;
                        self.pos.y += 1;
                    }
                    (None, None) => {
                        break;
                    }
                }

                println!("after move: {}", self.health);

                if self.health < self.lowest_health {
                    self.lowest_health = self.health;
                }
            }
        }
    }

    fn calculate_minimum_hp(dungeon: Vec<Vec<i32>>) -> i32 {
        let mut knight1 = Entity {
            health: dungeon[0][0],
            pos: Position { x: 0, y: 0 },
            lowest_health: 0,
        };
        if knight1.health < knight1.lowest_health {
            knight1.lowest_health = knight1.health;
        }
        let princess_pos = Position {
            x: dungeon[0].len(),
            y: dungeon.len(),
        };

        knight1.move_to(&princess_pos, &dungeon);

        let mut knight2 = Entity {
            health: dungeon[0][0],
            pos: Position { x: 0, y: 0 },
            lowest_health: 0,
        };
        if knight2.health < knight2.lowest_health {
            knight2.lowest_health = knight2.health;
        }
        let mut biggest_orb = (dungeon[0][0], Position { x: 0, y: 0 });

        for y in 0..dungeon.len() {
            for x in 0..dungeon[0].len() {
                if dungeon[y][x] > biggest_orb.0 {
                    biggest_orb = (dungeon[y][x], Position { x, y });
                }
            }
        }

        knight2.move_to(&biggest_orb.1, &dungeon);
        println!("knight2 halfway: {}", knight2.lowest_health);
        knight2.move_to(&princess_pos, &dungeon);

        println!("biggest_orb: {:?}", biggest_orb);

        println!("knight1: {}", knight1.lowest_health);
        println!("knight2: {}", knight2.lowest_health);

        if knight1.lowest_health > knight2.lowest_health {
            -knight1.lowest_health + 1
        } else {
            -knight2.lowest_health + 1
        }
    }

    #[test]
    fn test_calculate_minimum_hp() {
        assert_eq!(
            calculate_minimum_hp(vec![vec![1,2,1],vec![-2,-3,-3],vec![3,2,-2]]),
            1
        );
    }
}
