package com.httvc.androidjnidemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        TextView tt = (TextView) findViewById(R.id.sss_text);
        TextView sumText = (TextView) findViewById(R.id.sum_text);

        tv.setText(stringFromJNI());
        String appKey = NativeHelper.getAppKey();
        Log.d("sssssssss", appKey);

        NativeHelper.printLog("测试Log");

        //String text = Sample.sayHello("yanxin");
        String text = Sample.sayHellos("sssssss");
        tt.setText(text);

        IntArray intArray = new IntArray();
        int[] arr=new int[10];
        for (int i = 0; i <arr.length ; i++) {
            arr[i]=i;
        }
        int i = intArray.sumArray(arr);
        sumText.setText(i+"");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
