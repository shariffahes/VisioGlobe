package com.reactlibrary;
import android.content.Context;
import android.graphics.Color;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.TextView;
import android.view.View;
import android.view.LayoutInflater;
import androidx.annotation.NonNull;
import com.visioglobe.visiomoveessential.VMEMapView;
import com.visioglobe.visiomoveessential.listeners.VMELifeCycleListener;

public class CustomView extends FrameLayout {
  private View rootView;
  private VMEMapView mapView;
  public CustomView(@NonNull Context context) {
    super(context);
    // set padding and background color
    this.setPadding(16,16,16,16);
    this.setBackgroundColor(Color.parseColor("#5FD3F3"));
    LayoutInflater inflater = LayoutInflater.from(context);
    rootView = inflater.inflate(R.layout.map_view, null);
    mapView = (VMEMapView) rootView.findViewById(R.id.map);
    mapView.loadMap();
    this.addView(rootView);
  }

  public VMEMapView getMapView() {
    return mapView;
  }
}