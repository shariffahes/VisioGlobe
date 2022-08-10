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

public class MapView extends FrameLayout {
  private View rootView;
  private VMEMapView mapView;
  public MapView(@NonNull Context context) {
    super(context);
    LayoutInflater inflater = LayoutInflater.from(context);
    rootView = inflater.inflate(R.layout.map_view, null);
    mapView = (VMEMapView) rootView.findViewById(R.id.map);
    //mMapView.setPromptUserToDownloadMap(false);
    mapView.loadMap();
    this.addView(rootView);
  }

  public VMEMapView getVMEMapView() {
    return mapView;
  }
}