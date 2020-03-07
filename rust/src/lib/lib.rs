
//a mutable b is not
pub fn merge(a: &mut [i32], end_of_a : usize, b:  &[i32]) {
    let mut ia : i32 = (end_of_a -1) as i32;
    let mut ib : i32 = (b.len() -1) as i32;
    let mut im : i32 = (a.len() -1) as i32;
    while ib >= 0 {
        if ia >= 0 && (a[ia as usize] > b[ib as usize] ) {
            a[im as usize] = a[ia as usize];
            ia-=1;
        } else {
            a[im as usize] = b[ib as usize];
            ib-=1;
        }
        im-=1;
    }
}

pub fn rotated_search(a: &[i32], elem : i32) -> i32 {
    let mut min_start : i32 = 0;
    for i in 1 .. a.len() {
        if a[i-1] > a[i]  {
            min_start = i as i32;
            break;
        }
    }

    if elem >= a[min_start as usize] && elem <= a[a.len()-1] {
        return binary_search(a, min_start, (a.len()-1) as i32, elem);
    }
    return binary_search(a, 0, (min_start-1) as i32, elem)
}

pub fn binary_search(arr: &[i32], ll : i32, rr : i32, elem : i32) -> i32
{ 
    let mut l = ll;
    let mut r = rr;
    while l <= r { 
        let m = l + (r - l) / 2; 
  
        if arr[m as usize] == elem {
            return m; 
        }
        // ignore left half 
        if arr[m as usize] < elem {
            l = m + 1; 
        }
        // ignore right half 
        else {
            r = m - 1; 
        }
    } 

    // not present 
    return -1;
} 