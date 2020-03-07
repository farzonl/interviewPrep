
extern crate interviewprep;

pub fn main() {
}

#[test]
fn  ch10_1_merge_blarger() {
    let mut a: [i32; 4] = [1, 2, 0, 0];
    let b:  [i32; 2] = [3, 4];
    let sln: [i32; 4] = [1,2,3,4];
    interviewprep::merge(& mut a, 2,  &b);
    assert!(a.iter().zip(sln.iter()).all(|(a,b)| a == b), "Arrays are not equal");
}

#[test]
fn  ch10_1_merge_swizzle() {
    let mut a: [i32; 4] = [1, 3, 0, 0];
    let b:  [i32; 2] = [2, 4];
    let sln: [i32; 4] = [1,2,3,4];
    interviewprep::merge(& mut a, 2,  &b);
    assert!(a.iter().zip(sln.iter()).all(|(a,b)| a == b), "Arrays are not equal");
}

#[test]
fn  ch10_1_merge_alarger() {
    let mut a: [i32; 4] = [3, 4, 0, 0];
    let b:  [i32; 2] = [1, 2];
    let sln: [i32; 4] = [1,2,3,4];
    interviewprep::merge(& mut a, 2,  &b);
    assert!(a.iter().zip(sln.iter()).all(|(a,b)| a == b), "Arrays are not equal");
}
#[test]
fn  ch10_1_b_one_elem() {
    let mut a: [i32; 4] = [1, 3, 4, 0];
    let b:  [i32; 1] = [3];
    let sln: [i32; 4] = [1,3,3,4];
    interviewprep::merge(& mut a, 3,  &b);
    assert!(a.iter().zip(sln.iter()).all(|(a,b)| a == b), "Arrays are not equal");
}

#[test]
fn ch10_3_rotate_array() {
    //Input: find 5 in {15, 16, 19, 20, 25, 1, 3 ,4 ,5 ,7 ,10 , 14}
    // Array1: {10, 15, 20, 0, 5} Array2: {50,S, 20, 30, 40}
    let a:  [i32; 12] = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14];
    let b: [i32; 5] = [10, 15, 20, 0, 5];
    let c: [i32; 5] = [50, 5, 20, 30, 40];

     assert_eq!(interviewprep::rotated_search(&a, 5),8);
     assert_eq!(interviewprep::rotated_search(&b, 5),4);
     assert_eq!(interviewprep::rotated_search(&c, 5),1);
     assert_eq!(interviewprep::rotated_search(&c, 6),-1);
}